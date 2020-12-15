#include "utils/SubgraphFunctionGenerator.h"

#include "hal_core/netlist/boolean_function.h"
#include "hal_core/netlist/gate.h"
#include "hal_core/netlist/net.h"
#include "hal_core/netlist/netlist.h"
#include "hal_core/utilities/log.h"
#include "utils/BooleanFunctionWrapper.h"
#include "z3++.h"

#include <queue>

namespace hal
{
    namespace sat_solver_utils
    {
        BooleanFunction SubgraphFunctionGenerator::get_function_of_gate(const Gate* gate, const std::string& out_pin)
        {
            if (auto it = m_cache.find({gate->get_id(), out_pin}); it != m_cache.end())
            {
                return it->second;
            }
            BooleanFunction bf = gate->get_boolean_function(out_pin);

            if (bf.is_empty() && gate->get_type()->get_name() == "FDRE")
            {
                bf = BooleanFunction::from_string("D");
                // log_info("verification", "hard coded function {} for the ff type FDRE", bf.to_string());
            }

            if (bf.is_empty())
            {
                log_error("verification", "function of gate {} (type {}) associated with pin {} is empty!", gate->get_name(), gate->get_type()->get_name(), out_pin);
                return BooleanFunction();
            }

            // before replacing input pins with their connected net id, check if the function depends on other output pins
            auto output_pins = gate->get_output_pins();
            while (true)
            {
                auto vars = bf.get_variables();
                std::vector<std::string> output_pins_that_are_also_function_inputs;
                std::set_intersection(vars.begin(), vars.end(), output_pins.begin(), output_pins.end(), std::back_inserter(output_pins_that_are_also_function_inputs));

                if (output_pins_that_are_also_function_inputs.empty())
                {
                    break;
                }

                for (auto const& output_pin : output_pins_that_are_also_function_inputs)
                {
                    bf = bf.substitute(output_pin, gate->get_boolean_function(output_pin));
                }
            }

            // replace input pins with their connected net id
            for (auto const& input_pin : gate->get_input_pins())
            {
                const auto& input_net = gate->get_fan_in_net(input_pin);
                // std::cout << gate->get_id() << "\t" << gate->get_name() << "\t" << gate->get_type()->get_name() << "\t" << input_pin << std::endl;
                bf = bf.substitute(input_pin, std::to_string(input_net->get_id()));
            }

            m_cache.emplace(std::make_tuple(gate->get_id(), out_pin), bf);

            return bf;
        }

        void SubgraphFunctionGenerator::get_subgraph_z3_function(const Net* output_net, const std::vector<Gate*> subgraph_gates, z3::context& ctx, z3::expr& result)
        {
            // measure_block_time("generation of boolean function");
            /* check validity of subgraph_gates */
            if (subgraph_gates.empty())
            {
                log_error("verification", "parameter 'subgraph_gates' is empty");
                return ;
            }

            if (std::any_of(subgraph_gates.begin(), subgraph_gates.end(), [](auto& g) { return g == nullptr; }))
            {
                log_error("verification", "parameter 'subgraph_gates' contains a nullptr");
                return ;
            }

            if (output_net->get_num_of_sources() != 1)
            {
                log_error("verification", "target net {} has 0 or more than 1 sources.", output_net->get_name());
                return ;
            }

            for (const auto& gate : subgraph_gates)
            {
                if (gate->get_type()->get_base_type() == hal::GateType::BaseType::ff)
                {
                    log_error("verification", "subgraph contains ff/latch {}. aborting...", gate->get_name());
                    return ;
                }
            }

            std::queue<Net*> q;

            std::unordered_set<u32> input_net_ids;

            // prepare queue and result with initial gate
            {
                auto source     = output_net->get_sources()[0];
                auto start_gate = source->get_gate();

                auto f = get_function_of_gate(start_gate, source->get_pin());

                for (auto id_string : f.get_variables())
                {
                    input_net_ids.insert(std::stoi(id_string));
                }

                result = BooleanFunctionWrapper(f).to_z3_expr(ctx);

                for (auto& n : start_gate->get_fan_in_nets())
                {
                    q.push(n);
                }
            }

            while (!q.empty())
            {
                auto n = q.front();
                q.pop();

                if (n->get_num_of_sources() != 1)
                {
                    // log_error("verification", "net has 0 or more than 1 sources. not expanding the function here");
                    continue;
                }

                if (input_net_ids.find(n->get_id()) == input_net_ids.end())
                {
                    // log_info("verification", "net {} (id {}) is not an input to the function", n->get_name(), n->get_id());
                    continue;
                }

                auto src      = n->get_sources()[0];
                auto src_gate = src->get_gate();

                if (std::find(subgraph_gates.begin(), subgraph_gates.end(), src_gate) != subgraph_gates.end() || src_gate->get_type()->get_base_type() != hal::GateType::BaseType::ff)
                {
                    auto f = get_function_of_gate(src_gate, src->get_pin());

                    // substitute function into z3 expression
                    z3::expr_vector from_vec(ctx);
                    z3::expr_vector to_vec(ctx);

                    z3::expr from = ctx.bv_const(std::to_string(n->get_id()).c_str(), 1);
                    z3::expr to   = BooleanFunctionWrapper(f).to_z3_expr(ctx);

                    from_vec.push_back(from);
                    to_vec.push_back(to);

                    result = result.substitute(from_vec, to_vec);

                    // replace the net id which was substituted with all input ids of the substituted function
                    input_net_ids.erase(n->get_id());
                    for (auto id_string : f.get_variables())
                    {
                        input_net_ids.insert(std::stoi(id_string));
                    }

                    // add input nets of gate to queue
                    for (auto& sn : src_gate->get_fan_in_nets())
                    {
                        q.push(sn);
                    }
                }
            }

            result = result.simplify();
            return ;
        }
    }    // namespace sat_solver_utils
}    // namespace hal