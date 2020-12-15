#pragma once

#include "hal_core/plugin_system/plugin_interface_base.h"
#include "z3++.h"

#include <map>
#include <set>

namespace hal
{
    /* forward declaration */
    class Gate;
    class Netlist;
    class Net;

    class PLUGIN_API SATSolver : public BasePluginInterface
    {
    public:
        std::string get_name() const override;
        std::string get_version() const override;

        void initialize() override;

        std::vector<std::map<Net*, u32>>
            find_configuration(Netlist* nl, const std::vector<Gate*> subgraph, std::vector<Net*> input_nets, std::vector<Net*> output_nets, const std::vector<std::map<Net*, u32>> assignments);

    private:
        std::map<u32, u32> solve(z3::context ctx, std::map<std::map<z3::expr, u32>, std::map<z3::expr, u32>> input_to_output_assignments);
    };

}    // namespace hal
