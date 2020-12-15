#include "hal_core/netlist/boolean_function.h"
#include "hal_core/netlist/gate.h"
#include "hal_core/netlist/net.h"
#include "hal_core/netlist/netlist.h"
#include "z3++.h"

#include <vector>

namespace hal
{
    namespace sat_solver_utils
    {
        struct SubgraphFunctionGenerator
        {
            void get_subgraph_z3_function(const Net* output_net, const std::vector<Gate*> subgraph_gates, z3::context& ctx, z3::expr& result);
            SubgraphFunctionGenerator() = default;

        private:
            std::map<std::tuple<u32, std::string>, BooleanFunction> m_cache;
            BooleanFunction get_function_of_gate(const Gate* gate, const std::string& out_pin);
        };

    }    // namespace sat_solver_utils
}    // namespace hal