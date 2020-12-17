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

        std::vector<std::map<Net*, u32>> find_key_configuration(Netlist* nl,
                                                            const std::vector<Gate*> subgraph,
                                                            std::vector<Net*> input_nets,
                                                            std::vector<Net*> output_nets,
                                                            std::vector<Net*> key_bits,
                                                            const std::vector<std::map<Net*, u32>> assignments);

    private:
        std::vector<std::map<Net*, u32>> solve(z3::context* ctx,
                                                                std::vector<Net*> key_bits,
                                                                std::map<u32, z3::expr> output_net_to_z3_bf,
                                                                std::map<std::map<z3::expr, u32>, std::map<z3::expr, u32>> input_to_output_assignments);
    };

}    // namespace hal
