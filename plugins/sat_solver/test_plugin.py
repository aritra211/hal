#!/usr/bin/env python3
import sys, os

#some necessary configuration:
sys.path.append("/Users/eve/Uni/Projekte/hal/build/lib/") #this is where your hal python lib is located
os.environ["HAL_BASE_PATH"] = "/Users/eve/Uni/Projekte/hal/build/" # hal base path
import hal_py

netlist_to_read = "/Users/eve/Uni/Lehre/hwre-wise2021/02_Projekte/P3/Learning by doing/fulladder_obfuscated_netlist.v"
gate_library_path = "/Users/eve/Uni/Lehre/hwre-wise2021/02_Projekte/P3/Learning by doing/simpler.lib"

#initialize HAL
hal_py.plugin_manager.load_all_plugins()

#read netlist
netlist = hal_py.NetlistFactory.load_netlist(netlist_to_read, gate_library_path)

from hal_plugins import sat_solver

pl = hal_py.plugin_manager.get_plugin_instance("sat_solver")

assignments = list()

inputs = [netlist.get_net_by_id(7), netlist.get_net_by_id(9), netlist.get_net_by_id(8)]
outputs = [netlist.get_net_by_id(31), netlist.get_net_by_id(32)]
key_inputs = [netlist.get_net_by_id(3), netlist.get_net_by_id(4), netlist.get_net_by_id(5), netlist.get_net_by_id(6)]

cin = netlist.get_net_by_id(7)
a = netlist.get_net_by_id(9)
b = netlist.get_net_by_id(8)

sum = netlist.get_net_by_id(32)
cout = netlist.get_net_by_id(31)



for a_val in range(0,2):
    for b_val in range(0,2):
        for c_val in range(0,2):
            result = a_val + b_val + c_val
            expected_result = "{0:02b}".format(result)
            
            to_evaluate =  {a       : a_val,
                            b       : b_val,
                            cin     : c_val,
                            sum     : int(expected_result[0]),
                            cout    : int(expected_result[1])}
            assignments.append(to_evaluate)






pl.find_configuration(netlist, netlist.get_gates(), inputs, outputs, key_inputs, assignments)
#pl.execute(netlist)

#unload everything hal related
hal_py.plugin_manager.unload_all_plugins()