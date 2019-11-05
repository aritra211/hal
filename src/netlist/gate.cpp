#include "netlist/gate.h"

#include "netlist/module.h"
#include "netlist/net.h"
#include "netlist/netlist.h"

#include "netlist/event_system/gate_event_handler.h"

#include "core/log.h"

#include <assert.h>

gate::gate(std::shared_ptr<netlist> const g, const u32 id, std::shared_ptr<const gate_type> gt, const std::string& name)
{
    assert(g != nullptr);
    m_netlist = g;
    m_id      = id;
    m_type    = gt;
    m_name    = name;
}

std::ostream& operator<<(std::ostream& os, const gate& gate)
{
    os << "\t\'" << gate.get_name() << "\'"
       << " (type = '" << gate.get_type()->get_name() << "', id = " << gate.get_id() << ")" << std::endl;
    for (const auto& input_pin_type : gate.get_input_pin_types())
    {
        os << "\t\t" << input_pin_type << " => ";
        auto net = gate.get_fan_in_net(input_pin_type);
        if (net == nullptr)
            os << "nullptr";
        else
            os << net->get_name();
        os << std::endl;
    }
    for (const auto& output_pin_type : gate.get_output_pin_types())
    {
        os << "\t\t" << output_pin_type << " => ";
        auto net = gate.get_fan_out_net(output_pin_type);
        if (net == nullptr)
            os << "nullptr";
        else
            os << net->get_name();
        os << std::endl;
    }

    return os;
}

u32 gate::get_id() const
{
    return m_id;
}

std::shared_ptr<netlist> gate::get_netlist() const
{
    return m_netlist;
}

std::string gate::get_name() const
{
    return m_name;
}

void gate::set_name(const std::string& name)
{
    if (core_utils::trim(name).empty())
    {
        log_error("netlist.internal", "gate::set_name: empty name is not allowed");
        return;
    }
    if (name != m_name)
    {
        log_info("netlist.internal", "changed name for gate (id = {}, type = {}) from '{}' to '{}'.", m_id, m_type->get_name(), m_name, name);

        m_name = name;

        gate_event_handler::notify(gate_event_handler::event::name_changed, shared_from_this());
    }
}

std::shared_ptr<const gate_type> gate::get_type() const
{
    return m_type;
}

std::shared_ptr<module> gate::get_module() const
{
    return m_module;
}

boolean_function gate::get_boolean_function(const std::string& name) const
{
    if (name.empty())
    {
        auto output_pins = m_type->get_output_pins();
        if (!output_pins.empty())
        {
            return get_boolean_function(output_pins[0]);
        }
        return boolean_function::X;
    }
    auto it = m_functions.find(name);
    if (it == m_functions.end())
    {
        return it->second;
    }
    auto map = m_type->get_boolean_functions();
    it       = m_functions.find(name);
    if (it == m_functions.end())
    {
        return it->second;
    }
    return boolean_function::X;
}

std::map<std::string, boolean_function> gate::get_boolean_functions() const
{
    auto res = m_type->get_boolean_functions();

    for (const auto& it : m_functions)
    {
        res.emplace(it.first, it.second);
    }

    return res;
}

void gate::set_boolean_function(const std::string& name, const boolean_function& func)
{
    m_functions.emplace(name, func);
}

bool gate::mark_global_vcc_gate()
{
    return m_netlist->mark_global_vcc_gate(shared_from_this());
}

bool gate::mark_global_gnd_gate()
{
    return m_netlist->mark_global_gnd_gate(shared_from_this());
}

bool gate::unmark_global_vcc_gate()
{
    return m_netlist->unmark_global_vcc_gate(shared_from_this());
}

bool gate::unmark_global_gnd_gate()
{
    return m_netlist->unmark_global_gnd_gate(shared_from_this());
}

bool gate::is_global_vcc_gate() const
{
    return m_netlist->is_global_vcc_gate(const_cast<gate*>(this)->shared_from_this());
}

bool gate::is_global_gnd_gate() const
{
    return m_netlist->is_global_gnd_gate(const_cast<gate*>(this)->shared_from_this());
}

std::vector<std::string> gate::get_input_pin_types() const
{
    return m_type->get_input_pins();
}

std::vector<std::string> gate::get_output_pin_types() const
{
    return m_type->get_output_pins();
}

std::set<std::shared_ptr<net>> gate::get_fan_in_nets() const
{
    std::set<std::shared_ptr<net>> nets;

    for (const auto& it : m_in_nets)
    {
        nets.insert(it.second);
    }

    return nets;
}

std::shared_ptr<net> gate::get_fan_in_net(const std::string& pin_type) const
{
    auto it = m_in_nets.find(pin_type);

    if (it == m_in_nets.end())
    {
        log_debug("netlist.internal", "gate ('{},  type = {}) has no net connected to input pin '{}'.", get_name(), get_type()->get_name(), pin_type);
        return nullptr;
    }

    return it->second;
}

std::set<std::shared_ptr<net>> gate::get_fan_out_nets() const
{
    std::set<std::shared_ptr<net>> nets;

    for (const auto& it : m_out_nets)
    {
        nets.insert(it.second);
    }

    return nets;
}

std::shared_ptr<net> gate::get_fan_out_net(const std::string& pin_type) const
{
    auto it = m_out_nets.find(pin_type);

    if (it == m_out_nets.end())
    {
        log_debug("netlist.internal", "gate ('{},  type = {}) has no net connected to output pin '{}'.", get_name(), get_type()->get_name(), pin_type);
        return nullptr;
    }

    return it->second;
}

std::set<endpoint> gate::get_unique_predecessors(const std::string& this_pin_type_filter, const std::string& pred_pin_type_filter, const std::string& gate_type_filter) const
{
    auto predecessors = this->get_predecessors(this_pin_type_filter, pred_pin_type_filter, gate_type_filter);
    return std::set<endpoint>(predecessors.begin(), predecessors.end());
}

std::vector<endpoint> gate::get_predecessors(const std::string& this_pin_type_filter, const std::string& pred_pin_type_filter, const std::string& gate_type_filter) const
{
    if (this_pin_type_filter != DONT_CARE)
    {
        auto it = m_in_nets.find(this_pin_type_filter);
        if (it == m_in_nets.end())
        {
            return {};
        }
        auto net  = it->second;
        auto pred = net->get_src();
        if (pred.gate == nullptr)
        {
            log_debug("netlist", "predecessor on pin '{}' of gate '{}' (id = {:08x}) is unrouted.", this_pin_type_filter, this->get_name(), this->get_id());
            return {};
        }
        if ((pred_pin_type_filter != DONT_CARE) && (pred.pin_type != pred_pin_type_filter))
        {
            log_debug("netlist", "pin type of predecessor gate '{}' (id = {:08x}) does not match", pred.gate->get_name(), pred.gate->get_id());
            return {};
        }
        if ((gate_type_filter != DONT_CARE) && (pred.gate->get_type()->get_name() != gate_type_filter))
        {
            log_debug("netlist", "type of predecessor gate '{}' (id = {:08x}) does not match", pred.gate->get_name(), pred.gate->get_id());
            return {};
        }
        log_debug(
            "netlist", "predecessor of ('{}', {}) is ('{}', {}) in net '{}' (id = {:08x})", get_name(), pred_pin_type_filter, pred.gate->get_name(), pred.pin_type, net->get_name(), net->get_id());
        return {pred};
    }
    else
    {
        std::vector<endpoint> result;
        for (const auto& it : m_in_nets)
        {
            auto net  = it.second;
            auto pred = net->get_src();
            if (pred.gate == nullptr)
            {
                log_debug("netlist", "predecessor on pin '{}' of gate '{}' (id = {:08x}) is unrouted.", it.first, this->get_name(), this->get_id());
                continue;
            }
            if ((pred_pin_type_filter != DONT_CARE) && (pred.pin_type != pred_pin_type_filter))
            {
                log_debug("netlist", "pin type of predecessor gate '{}' (id = {:08x}) does not match", pred.gate->get_name(), pred.gate->get_id());
                continue;
            }
            if ((gate_type_filter != DONT_CARE) && (pred.gate->get_type()->get_name() != gate_type_filter))
            {
                log_debug("netlist", "type of predecessor gate '{}' (id = {:08x}) does not match", pred.gate->get_name(), pred.gate->get_id());
                continue;
            }

            log_debug(
                "netlist", "predecessor of ('{}', {}) is ('{}', {}) in net '{}' (id = {:08x})", get_name(), pred_pin_type_filter, pred.gate->get_name(), pred.pin_type, net->get_name(), net->get_id());
            result.push_back(pred);
        }
        return result;
    }
}

endpoint gate::get_predecessor(const std::string& this_pin_type_filter, const std::string& pred_pin_type_filter, const std::string& gate_type_filter) const
{
    auto predecessors = this->get_predecessors(this_pin_type_filter, pred_pin_type_filter, gate_type_filter);
    if (predecessors.size() == 0)
    {
        return {nullptr, ""};
    }
    if (predecessors.size() > 1)
    {
        log_error("netlist", "internal error: multiple predecessors for '{}' at pin '{}'.", get_name(), pred_pin_type_filter);
        return {nullptr, ""};
    }

    return *(predecessors.begin());
}

std::set<endpoint> gate::get_unique_successors(const std::string& this_pin_type_filter, const std::string& suc_pin_type_filter, const std::string& gate_type_filter) const
{
    auto successors = this->get_successors(this_pin_type_filter, suc_pin_type_filter, gate_type_filter);
    return std::set<endpoint>(successors.begin(), successors.end());
}

std::vector<endpoint> gate::get_successors(const std::string& this_pin_type_filter, const std::string& suc_pin_type_filter, const std::string& gate_type_filter) const
{
    std::vector<endpoint> result;
    if (this_pin_type_filter != DONT_CARE)
    {
        auto it = m_out_nets.find(this_pin_type_filter);
        if (it == m_out_nets.end())
        {
            return result;
        }
        auto net        = it->second;
        auto successors = net->get_dsts();
        for (const auto& suc : successors)
        {
            if ((suc_pin_type_filter != DONT_CARE) && (suc.pin_type != suc_pin_type_filter))
            {
                log_debug("netlist", "pin type of successor gate '{}' (id = {:08x}) does not match", suc.gate->get_name(), suc.gate->get_id());
                continue;
            }
            if ((gate_type_filter != DONT_CARE) && (suc.gate->get_type()->get_name() != gate_type_filter))
            {
                log_debug("netlist", "type of successor gate '{}' (id = {:08x}) does not match", suc.gate->get_name(), suc.gate->get_id());
                continue;
            }

            log_debug(
                "netlist", "successor of ('{}', {}) is ('{}', {}) in net '{}' (id = {:08x})", get_name(), suc_pin_type_filter, suc.gate->get_name(), suc.pin_type, net->get_name(), net->get_id());
            result.push_back(suc);
        }
    }
    else
    {
        for (const auto& it : m_out_nets)
        {
            auto net        = it.second;
            auto successors = net->get_dsts();
            for (const auto& suc : successors)
            {
                if ((suc_pin_type_filter != DONT_CARE) && (suc.pin_type != suc_pin_type_filter))
                {
                    log_debug("netlist", "pin type of successor gate '{}' (id = {:08x}) does not match", suc.gate->get_name(), suc.gate->get_id());
                    continue;
                }
                if ((gate_type_filter != DONT_CARE) && (suc.gate->get_type()->get_name() != gate_type_filter))
                {
                    log_debug("netlist", "type of successor gate '{}' (id = {:08x}) does not match", suc.gate->get_name(), suc.gate->get_id());
                    continue;
                }

                log_debug(
                    "netlist", "successor of ('{}', {}) is ('{}', {}) in net '{}' (id = {:08x})", get_name(), suc_pin_type_filter, suc.gate->get_name(), suc.pin_type, net->get_name(), net->get_id());
                result.push_back(suc);
            }
        }
    }
    return result;
}
