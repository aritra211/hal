#include "sat_solver/plugin_sat_solver.h"

#include "hal_core/netlist/boolean_function.h"
#include "hal_core/netlist/endpoint.h"
#include "hal_core/netlist/gate.h"
#include "hal_core/netlist/gate_library/gate_type/gate_type.h"
#include "hal_core/netlist/module.h"
#include "hal_core/netlist/net.h"
#include "hal_core/netlist/netlist.h"
#include "hal_core/netlist/persistent/netlist_serializer.h"
#include "hal_core/plugin_system/plugin_manager.h"
#include "utils/SubgraphFunctionGenerator.h"
#include "z3++.h"

#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <vector>

namespace hal
{
    extern std::unique_ptr<BasePluginInterface> create_plugin_instance()
    {
        return std::make_unique<SATSolver>();
    }

    std::string SATSolver::get_name() const
    {
        return std::string("sat_solver");
    }

    std::string SATSolver::get_version() const
    {
        return std::string("0.1");
    }

    void SATSolver::initialize()
    {
    }

    std::vector<std::map<Net*, u32>> SATSolver::find_configuration(Netlist* nl,
                                                                   const std::vector<Gate*> subgraph,
                                                                   std::vector<Net*> input_nets,
                                                                   std::vector<Net*> output_nets,
                                                                   std::vector<Net*> key_bits,
                                                                   const std::vector<std::map<Net*, u32>> assignments)
    {
        log_info("sat_solver", "starting to look for configurations...");

        z3::context ctx;
        sat_solver_utils::SubgraphFunctionGenerator subgraph_function_generator;

        std::map<u32, z3::expr> output_net_to_z3_expr;
        for (const auto& net : output_nets)
        {
            z3::expr result(ctx);
            subgraph_function_generator.get_subgraph_z3_function(net, subgraph, ctx, result);
            output_net_to_z3_expr.insert(std::make_pair(net->get_id(), result.simplify()));
        }

        for (const auto& [net, z3_bf] : output_net_to_z3_expr)
        {
            log_info("sat_solver", "z3 boolean function for net {}...", net);
            std::cout << z3_bf << std::endl;
        }

        log_info("sat_solver", "building input to output assignments now");

        std::map<std::map<z3::expr, u32>, std::map<z3::expr, u32>> input_to_output_assignments;
        for (const auto& assignment : assignments)
        {
            std::map<z3::expr, u32> input_assignments;
            std::map<z3::expr, u32> output_assignments;

            for (const auto& [net, value] : assignment)
            {
                if (std::find(input_nets.begin(), input_nets.end(), net) != input_nets.end())
                {
                    z3::expr input           = ctx.bv_const(std::to_string(net->get_id()).c_str(), 1);
                    input_assignments[input] = value;
                }
                else if (std::find(output_nets.begin(), output_nets.end(), net) != output_nets.end())
                {
                    z3::expr output            = ctx.bv_const(std::to_string(net->get_id()).c_str(), 1);
                    output_assignments[output] = value;
                }
                else
                {
                    log_error("sat_solver", "you assigned a value to net {}, which is neither in input vector, nor in the output vector. aborting...", net->get_name());
                    return std::vector<std::map<Net*, u32>>();
                }
            }
            input_to_output_assignments[input_assignments] = output_assignments;
        }
        log_info("sat_solver", "starting sat solver");

        solve(&ctx, key_bits, output_net_to_z3_expr, input_to_output_assignments);

        return std::vector<std::map<Net*, u32>>();
    }

    std::map<u32, u32> SATSolver::solve(z3::context* ctx,
                                        std::vector<Net*> key_bits,
                                        std::map<u32, z3::expr> output_net_to_z3_bf,
                                        std::map<std::map<z3::expr, u32>, std::map<z3::expr, u32>> input_to_output_assignments)
    {
        z3::solver s(*ctx);
        for (const auto& [net_id, z3_bf] : output_net_to_z3_bf)
        {
            s.add(z3_bf == ctx->bv_const(std::to_string(net_id).c_str(), 1));
        }

        std::cout << s << std::endl;

        for (const auto& [in_assign, out_assign] : input_to_output_assignments)
        {
            z3::expr assign_input_z3 = ctx->bool_val(1);
            for (const auto& [z3_var, value] : in_assign)
            {
                z3::expr temp   = (z3_var == ctx->bv_val(value, 1));
                assign_input_z3 = assign_input_z3 && temp;
            }

            z3::expr assign_output_z3 = ctx->bool_val(1);
            for (const auto& [z3_var, value] : out_assign)
            {
                z3::expr temp    = (z3_var == ctx->bv_val(value, 1));
                assign_output_z3 = assign_output_z3 & temp;
            }

            z3::expr assign_z3(*ctx);
            assign_z3 = implies(assign_input_z3, assign_output_z3);

            s.add(assign_z3);

            std::cout << assign_z3 << std::endl;
        }
        auto result = s.check();

        // add found solution to constrains, so we can make sure, that we found every possible key

        std::vector<std::map<u32, u32>> possible_values;
        while (true)
        {
            auto result = s.check();

            if (result == z3::sat)
            {
                auto m = s.get_model();
                std::cout << "model: " << m << std::endl;

                z3::expr to_add = ctx->bool_val(0);
                for (const auto& key_bit : key_bits)
                {
                    z3::expr key_bit_z3 = ctx->bv_const(std::to_string(key_bit->get_id()).c_str(), 1);
                    z3::expr temp = (key_bit_z3 != m.eval(key_bit_z3));
                    to_add        = to_add || temp;
                }
                s.add(to_add == ctx->bool_val(0));
                std::cout << "added: " << to_add << std::endl;

                std::cout << "solver: " << s << std::endl;

            }
            else
            {
                break;
            }
        }
        /*
        std::vector<FsmTransition> successor_transitions;

        auto s = z3::solver(prev_state_vec.ctx());
        s.add(prev_state_vec == start_state);

        while (true)
        {
            auto result = s.check();

            if (result == z3::sat)
            {
                auto m = s.get_model();
                auto n = m.eval(next_state_vec);

                // check wether the next state only depends on the prev state (is numeral) or contains external inputs
                if (n.is_numeral())
                {
                    successor_transitions.push_back({start_state, n, {}});
                }
                else
                {
                    auto relevant_inputs = get_relevant_external_inputs(n, external_ids_to_expr);
                    for (u64 i = 0; i < pow(2, relevant_inputs.size()); i++)
                    {
                        auto transition = generate_transition_with_inputs(start_state, n, relevant_inputs, i);
                        successor_transitions.push_back(transition);
                    }
                }
                s.add(next_state_vec != n);
            }
            else
            {
                break;
            }
        }

        return successor_transitions;
        */
        return std::map<u32, u32>();
    }

}    // namespace hal
