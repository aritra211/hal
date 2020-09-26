Search.setIndex({docnames:["boolean_function","core_utils","data_container","endpoint","gate","gate_library","gate_type","gate_type_lut","gate_type_sequential","graph_algorithm","gui","gui_plugin_interface","hal_gui","hal_py","hdl_writer_manager","i_base","index","module","net","netlist","netlist_factory","path","plugin_manager"],envversion:{"sphinx.domains.c":1,"sphinx.domains.changeset":1,"sphinx.domains.cpp":1,"sphinx.domains.javascript":1,"sphinx.domains.math":2,"sphinx.domains.python":1,"sphinx.domains.rst":1,"sphinx.domains.std":1,"sphinx.ext.intersphinx":1,"sphinx.ext.todo":1,sphinx:55},filenames:["boolean_function.rst","core_utils.rst","data_container.rst","endpoint.rst","gate.rst","gate_library.rst","gate_type.rst","gate_type_lut.rst","gate_type_sequential.rst","graph_algorithm.rst","gui.rst","gui_plugin_interface.rst","hal_gui.rst","hal_py.rst","hdl_writer_manager.rst","i_base.rst","index.rst","module.rst","net.rst","netlist.rst","netlist_factory.rst","path.rst","plugin_manager.rst"],objects:{"hal_gui.GuiApi":{deselect:[10,1,1,""],deselect_all_items:[10,1,1,""],deselect_gate:[10,1,1,""],deselect_module:[10,1,1,""],deselect_net:[10,1,1,""],get_selected_gate_ids:[10,1,1,""],get_selected_gates:[10,1,1,""],get_selected_item_ids:[10,1,1,""],get_selected_items:[10,1,1,""],get_selected_module_ids:[10,1,1,""],get_selected_modules:[10,1,1,""],get_selected_net_ids:[10,1,1,""],get_selected_nets:[10,1,1,""],select:[10,1,1,""],select_gate:[10,1,1,""],select_module:[10,1,1,""],select_net:[10,1,1,""]},"hal_py.BooleanFunction":{__init__:[0,1,1,""],evaluate:[0,1,1,""],from_string:[0,2,1,""],get_truth_table:[0,1,1,""],get_variables:[0,1,1,""],is_constant_one:[0,1,1,""],is_constant_zero:[0,1,1,""],is_dnf:[0,1,1,""],is_empty:[0,1,1,""],optimize:[0,1,1,""],substitute:[0,1,1,""],to_dnf:[0,1,1,""],value:[0,0,1,""],variables:[0,3,1,""]},"hal_py.BooleanFunction.value":{name:[0,3,1,""]},"hal_py.CoreUtils":{get_base_directory:[1,5,1,""],get_binary_directory:[1,5,1,""],get_default_log_directory:[1,5,1,""],get_gate_library_directories:[1,5,1,""],get_library_directory:[1,5,1,""],get_plugin_directories:[1,5,1,""],get_share_directory:[1,5,1,""],get_user_config_directory:[1,5,1,""],get_user_share_directory:[1,5,1,""]},"hal_py.DataContainer":{data:[2,3,1,""],data_keys:[2,3,1,""],delete_data:[2,1,1,""],get_data_by_key:[2,1,1,""],set_data:[2,1,1,""]},"hal_py.Endpoint":{__init__:[3,1,1,""],gate:[3,3,1,""],get_gate:[3,1,1,""],get_net:[3,1,1,""],get_pin:[3,1,1,""],is_destination:[3,3,1,""],is_destination_pin:[3,1,1,""],is_source:[3,3,1,""],is_source_pin:[3,1,1,""],net:[3,3,1,""],pin:[3,3,1,""]},"hal_py.GUIPluginInterface":{exec:[11,1,1,""]},"hal_py.Gate":{add_boolean_function:[4,1,1,""],boolean_functions:[4,3,1,""],data:[4,3,1,""],data_keys:[4,3,1,""],delete_data:[4,1,1,""],fan_in_nets:[4,3,1,""],fan_out_nets:[4,3,1,""],get_boolean_function:[4,1,1,""],get_boolean_functions:[4,1,1,""],get_data_by_key:[4,1,1,""],get_fan_in_endpoints:[4,1,1,""],get_fan_in_net:[4,1,1,""],get_fan_in_nets:[4,1,1,""],get_fan_out_endpoint:[4,1,1,""],get_fan_out_endpoints:[4,1,1,""],get_fan_out_net:[4,1,1,""],get_fan_out_nets:[4,1,1,""],get_id:[4,1,1,""],get_input_pins:[4,1,1,""],get_location:[4,1,1,""],get_location_x:[4,1,1,""],get_location_y:[4,1,1,""],get_module:[4,1,1,""],get_name:[4,1,1,""],get_netlist:[4,1,1,""],get_output_pins:[4,1,1,""],get_predecessor:[4,1,1,""],get_predecessors:[4,1,1,""],get_successor:[4,1,1,""],get_successors:[4,1,1,""],get_type:[4,1,1,""],get_unique_predecessors:[4,1,1,""],get_unique_successors:[4,1,1,""],has_location:[4,1,1,""],id:[4,3,1,""],input_pins:[4,3,1,""],is_gnd_gate:[4,1,1,""],is_vcc_gate:[4,1,1,""],location:[4,3,1,""],location_x:[4,3,1,""],location_y:[4,3,1,""],mark_gnd_gate:[4,1,1,""],mark_vcc_gate:[4,1,1,""],module:[4,3,1,""],name:[4,3,1,""],netlist:[4,3,1,""],output_pins:[4,3,1,""],predecessors:[4,3,1,""],set_data:[4,1,1,""],set_location:[4,1,1,""],set_location_x:[4,1,1,""],set_location_y:[4,1,1,""],set_name:[4,1,1,""],successors:[4,3,1,""],type:[4,3,1,""],unique_predecessors:[4,3,1,""],unique_successors:[4,3,1,""],unmark_gnd_gate:[4,1,1,""],unmark_vcc_gate:[4,1,1,""]},"hal_py.GateLibrary":{__init__:[5,1,1,""],add_include:[5,1,1,""],gate_types:[5,3,1,""],get_gate_types:[5,1,1,""],get_gnd_gate_types:[5,1,1,""],get_includes:[5,1,1,""],get_name:[5,1,1,""],get_path:[5,1,1,""],get_vcc_gate_types:[5,1,1,""],gnd_gate_types:[5,3,1,""],includes:[5,3,1,""],name:[5,3,1,""],path:[5,3,1,""],vcc_gate_types:[5,3,1,""]},"hal_py.GateType":{BaseType:[6,0,1,""],__init__:[6,1,1,""],add_boolean_function:[6,1,1,""],add_boolean_functions:[6,1,1,""],add_input_pin:[6,1,1,""],add_input_pins:[6,1,1,""],add_output_pin:[6,1,1,""],add_output_pins:[6,1,1,""],assign_input_pin_group:[6,1,1,""],assign_input_pin_groups:[6,1,1,""],assign_output_pin_group:[6,1,1,""],assign_output_pin_groups:[6,1,1,""],boolean_functions:[6,3,1,""],get_base_type:[6,1,1,""],get_boolean_functions:[6,1,1,""],get_input_pin_groups:[6,1,1,""],get_input_pins:[6,1,1,""],get_name:[6,1,1,""],get_output_pin_groups:[6,1,1,""],get_output_pins:[6,1,1,""],input_pins:[6,3,1,""],name:[6,3,1,""],output_pins:[6,3,1,""]},"hal_py.GateType.BaseType":{name:[6,3,1,""]},"hal_py.GateTypeLut":{BaseType:[7,0,1,""],__init__:[7,1,1,""],add_boolean_function:[7,1,1,""],add_boolean_functions:[7,1,1,""],add_input_pin:[7,1,1,""],add_input_pins:[7,1,1,""],add_output_from_init_string_pin:[7,1,1,""],add_output_pin:[7,1,1,""],add_output_pins:[7,1,1,""],assign_input_pin_group:[7,1,1,""],assign_input_pin_groups:[7,1,1,""],assign_output_pin_group:[7,1,1,""],assign_output_pin_groups:[7,1,1,""],boolean_functions:[7,3,1,""],config_data_ascending_order:[7,3,1,""],config_data_category:[7,3,1,""],config_data_identifier:[7,3,1,""],get_base_type:[7,1,1,""],get_boolean_functions:[7,1,1,""],get_config_data_category:[7,1,1,""],get_config_data_identifier:[7,1,1,""],get_input_pin_groups:[7,1,1,""],get_input_pins:[7,1,1,""],get_name:[7,1,1,""],get_output_from_init_string_pins:[7,1,1,""],get_output_pin_groups:[7,1,1,""],get_output_pins:[7,1,1,""],input_pins:[7,3,1,""],is_config_data_ascending_order:[7,1,1,""],name:[7,3,1,""],output_from_init_string_pins:[7,3,1,""],output_pins:[7,3,1,""],set_config_data_ascending_order:[7,1,1,""],set_config_data_category:[7,1,1,""],set_config_data_identifier:[7,1,1,""]},"hal_py.GateTypeLut.BaseType":{name:[7,3,1,""]},"hal_py.GateTypeSequential":{BaseType:[8,0,1,""],SetResetBehavior:[8,0,1,""],__init__:[8,1,1,""],add_boolean_function:[8,1,1,""],add_boolean_functions:[8,1,1,""],add_clock_pin:[8,1,1,""],add_input_pin:[8,1,1,""],add_input_pins:[8,1,1,""],add_inverted_state_output_pin:[8,1,1,""],add_output_pin:[8,1,1,""],add_output_pins:[8,1,1,""],add_state_output_pin:[8,1,1,""],assign_input_pin_group:[8,1,1,""],assign_input_pin_groups:[8,1,1,""],assign_output_pin_group:[8,1,1,""],assign_output_pin_groups:[8,1,1,""],boolean_functions:[8,3,1,""],get_base_type:[8,1,1,""],get_boolean_functions:[8,1,1,""],get_clock_pins:[8,1,1,""],get_init_data_category:[8,1,1,""],get_init_data_identifier:[8,1,1,""],get_input_pin_groups:[8,1,1,""],get_input_pins:[8,1,1,""],get_inverted_state_output_pins:[8,1,1,""],get_name:[8,1,1,""],get_output_pin_groups:[8,1,1,""],get_output_pins:[8,1,1,""],get_set_reset_behavior:[8,1,1,""],get_state_output_pins:[8,1,1,""],init_data_category:[8,3,1,""],init_data_identifier:[8,3,1,""],input_pins:[8,3,1,""],name:[8,3,1,""],output_pins:[8,3,1,""],set_init_data_category:[8,1,1,""],set_init_data_identifier:[8,1,1,""],set_set_reset_behavior:[8,1,1,""]},"hal_py.GateTypeSequential.BaseType":{name:[8,3,1,""]},"hal_py.GateTypeSequential.SetResetBehavior":{name:[8,3,1,""]},"hal_py.HalPath":{__init__:[21,1,1,""],__str__:[21,1,1,""]},"hal_py.Module":{assign_gate:[17,1,1,""],contains_gate:[17,1,1,""],contains_module:[17,1,1,""],data:[17,3,1,""],data_keys:[17,3,1,""],delete_data:[17,1,1,""],gates:[17,3,1,""],get_data_by_key:[17,1,1,""],get_gate_by_id:[17,1,1,""],get_gates:[17,1,1,""],get_id:[17,1,1,""],get_input_nets:[17,1,1,""],get_input_port_name:[17,1,1,""],get_input_port_names:[17,1,1,""],get_internal_nets:[17,1,1,""],get_name:[17,1,1,""],get_netlist:[17,1,1,""],get_output_nets:[17,1,1,""],get_output_port_name:[17,1,1,""],get_output_port_names:[17,1,1,""],get_parent_module:[17,1,1,""],get_submodules:[17,1,1,""],get_type:[17,1,1,""],id:[17,3,1,""],input_nets:[17,3,1,""],input_port_names:[17,3,1,""],internal_nets:[17,3,1,""],name:[17,3,1,""],netlist:[17,3,1,""],output_nets:[17,3,1,""],output_port_names:[17,3,1,""],parent_module:[17,3,1,""],remove_gate:[17,1,1,""],set_data:[17,1,1,""],set_input_port_name:[17,1,1,""],set_name:[17,1,1,""],set_output_port_name:[17,1,1,""],set_parent_module:[17,1,1,""],set_type:[17,1,1,""],submodules:[17,3,1,""],type:[17,3,1,""]},"hal_py.Net":{add_destination:[18,1,1,""],add_source:[18,1,1,""],data:[18,3,1,""],data_keys:[18,3,1,""],delete_data:[18,1,1,""],destinations:[18,3,1,""],get_data_by_key:[18,1,1,""],get_destinations:[18,1,1,""],get_id:[18,1,1,""],get_name:[18,1,1,""],get_num_of_destinations:[18,1,1,""],get_num_of_sources:[18,1,1,""],get_source:[18,1,1,""],get_sources:[18,1,1,""],id:[18,3,1,""],is_a_destination:[18,1,1,""],is_a_source:[18,1,1,""],is_global_input_net:[18,1,1,""],is_global_output_net:[18,1,1,""],is_unrouted:[18,1,1,""],mark_global_input_net:[18,1,1,""],mark_global_output_net:[18,1,1,""],name:[18,3,1,""],num_of_destinations:[18,3,1,""],num_of_sources:[18,3,1,""],remove_destination:[18,1,1,""],remove_source:[18,1,1,""],set_data:[18,1,1,""],set_name:[18,1,1,""],sources:[18,3,1,""],unmark_global_input_net:[18,1,1,""],unmark_global_output_net:[18,1,1,""]},"hal_py.Netlist":{GateLibrary:[19,3,1,""],create_gate:[19,1,1,""],create_module:[19,1,1,""],create_net:[19,1,1,""],delete_gate:[19,1,1,""],delete_module:[19,1,1,""],delete_net:[19,1,1,""],design_name:[19,3,1,""],device_name:[19,3,1,""],gates:[19,3,1,""],get_design_name:[19,1,1,""],get_device_name:[19,1,1,""],get_gate_by_id:[19,1,1,""],get_gate_library:[19,1,1,""],get_gates:[19,1,1,""],get_global_input_nets:[19,1,1,""],get_global_output_nets:[19,1,1,""],get_gnd_gates:[19,1,1,""],get_id:[19,1,1,""],get_input_filename:[19,1,1,""],get_module_by_id:[19,1,1,""],get_modules:[19,1,1,""],get_net_by_id:[19,1,1,""],get_nets:[19,1,1,""],get_top_module:[19,1,1,""],get_unique_gate_id:[19,1,1,""],get_unique_module_id:[19,1,1,""],get_unique_net_id:[19,1,1,""],get_vcc_gates:[19,1,1,""],global_input_nets:[19,3,1,""],global_output_nets:[19,3,1,""],gnd_gates:[19,3,1,""],id:[19,3,1,""],input_filename:[19,3,1,""],is_gate_in_netlist:[19,1,1,""],is_global_input_net:[19,1,1,""],is_global_output_net:[19,1,1,""],is_gnd_gate:[19,1,1,""],is_module_in_netlist:[19,1,1,""],is_net_in_netlist:[19,1,1,""],is_vcc_gate:[19,1,1,""],mark_global_input_net:[19,1,1,""],mark_global_output_net:[19,1,1,""],mark_gnd_gate:[19,1,1,""],mark_vcc_gate:[19,1,1,""],modules:[19,3,1,""],nets:[19,3,1,""],set_design_name:[19,1,1,""],set_device_name:[19,1,1,""],set_id:[19,1,1,""],set_input_filename:[19,1,1,""],top_module:[19,3,1,""],unmark_global_input_net:[19,1,1,""],unmark_global_output_net:[19,1,1,""],unmark_gnd_gate:[19,1,1,""],unmark_vcc_gate:[19,1,1,""],vcc_gates:[19,3,1,""]},"hal_py.NetlistFactory":{create_netlist:[20,5,1,""],load_netlist:[20,5,1,""],load_netlists:[20,5,1,""]},"hal_py.hdl_writer_manager":{get_cli_options:[14,5,1,""],write:[14,5,1,""]},"hal_py.i_base":{get_name:[15,1,1,""],get_version:[15,1,1,""],name:[15,3,1,""],version:[15,3,1,""]},"hal_py.plugin_manager":{get_plugin_instance:[22,5,1,""],get_plugin_names:[22,5,1,""],load:[22,5,1,""],load_all_plugins:[22,5,1,""],unload_all_plugins:[22,5,1,""]},hal_gui:{GuiApi:[10,0,1,""]},hal_py:{BooleanFunction:[0,0,1,""],CoreUtils:[1,4,0,"-"],DataContainer:[2,0,1,""],Endpoint:[3,0,1,""],GUIPluginInterface:[11,0,1,""],Gate:[4,0,1,""],GateLibrary:[5,0,1,""],GateType:[6,0,1,""],GateTypeLut:[7,0,1,""],GateTypeSequential:[8,0,1,""],HalPath:[21,0,1,""],Module:[17,0,1,""],Net:[18,0,1,""],Netlist:[19,0,1,""],NetlistFactory:[20,4,0,"-"],hdl_writer_manager:[14,4,0,"-"],i_base:[15,0,1,""],plugin_manager:[22,4,0,"-"]}},objnames:{"0":["py","class","Python class"],"1":["py","method","Python method"],"2":["py","staticmethod","Python static method"],"3":["py","attribute","Python attribute"],"4":["py","module","Python module"],"5":["py","function","Python function"]},objtypes:{"0":"py:class","1":"py:method","2":"py:staticmethod","3":"py:attribute","4":"py:module","5":"py:function"},terms:{"boolean":[4,6,7,8,13],"class":[0,2,3,4,5,6,7,8,10,11,15,17,18,19,21],"default":[1,2,4,17,18,22],"float":[4,19],"function":[1,4,6,7,8,10,13,18,19,20,21],"int":[4,6,7,8,10,17,18,19],"new":[0,4,6,7,8,17,18,19,20],"null":18,"return":[0,1,2,3,4,5,6,7,8,10,11,14,15,17,18,19,20,22],"static":[0,1],"true":[0,2,3,4,7,10,11,14,17,18,19,22],"try":1,AND:0,NOT:0,ONE:[0,8],The:[0,1,2,3,4,5,6,7,8,10,11,14,15,17,18,19,20,22],Use:1,__init__:[0,3,5,6,7,8,21],__str__:21,about:[4,5,6,7,8,17,18,19],accur:[3,5],activ:8,add:[4,5,6,7,8,17,18,19],add_boolean_funct:[4,6,7,8],add_clock_pin:8,add_destin:18,add_includ:5,add_input_pin:[6,7,8],add_inverted_state_output_pin:8,add_output_from_init_string_pin:7,add_output_pin:[6,7,8],add_sourc:18,add_state_output_pin:8,added:[2,4,10,17,18],again:0,algorithm:[0,13],all:[0,2,4,5,6,7,8,10,17,18,19,22],alphabet:0,also:[0,17],anoth:[0,17],api:12,appli:0,arg0:[0,21],arg:[0,4,10,18,19,20,21],ascend:[0,7],assign:[4,6,7,8],assign_g:17,assign_input_pin_group:[6,7,8],assign_output_pin_group:[6,7,8],associ:[4,17,19,22],aswel:17,automat:19,avail:[0,4,6,7,8],base:[1,4,6,7,8,13,17,18,22],baseplugininterfac:22,basetyp:[6,7,8],basic:22,befor:[0,10,19],beforehand:8,behavior:8,belong:17,binari:1,bit:7,bool:[0,2,3,4,7,10,11,14,17,18,19,22],boolean_funct:[4,6,7,8],booleanfunct:[0,4,6,7,8],both:8,bracket:0,call:11,callabl:[4,17,18,19],camera:10,can:[0,4,6,7,8,17,19],categori:[2,4,7,8,17,18],cell:8,chang:[8,17,19],channel:[2,4,17,18],check:[0,3,4,17,18,19],clear:10,clear_current_select:10,clock:8,collect:[7,8],combin:0,combinatori:[6,7,8],command:14,config:1,config_data_ascending_ord:7,config_data_categori:7,config_data_identifi:7,configur:1,connect:[4,8],constant:[0,4],constantli:0,construct:[6,7,8],constructor:0,contain:[0,1,4,5,6,7,8,13,17,18,19],contains_g:17,contains_modul:17,content:16,convert:0,coordin:[4,19],core:13,coreutil:1,correspond:17,creat:[19,20],create_g:19,create_modul:19,create_net:19,create_netlist:20,current:[1,10],custom:[2,4,17,18],data:[4,13,17,18],data_kei:[2,4,17,18],data_typ:[2,4,17,18],datacontain:[2,4,17,18],declar:8,defin:[4,14],delet:[2,4,17,18],delete_data:[2,4,17,18],delete_g:19,delete_modul:19,delete_net:19,describ:8,deselect:10,deselect_all_item:10,deselect_g:10,deselect_modul:10,deselect_net:10,design:19,design_nam:19,desir:[18,22],destin:[3,17,18],determin:[1,10],devic:19,device_nam:19,dict:[0,2,4,5,6,7,8,17,18],dictp:5,direct:[4,17],directori:[1,22],dispatch:14,divice_nam:19,dnf:0,doe:[2,4,17,18],dure:0,each:20,either:[0,6,7,8,17],empti:[0,4,18,22],endpoint:[4,13,18],entri:[2,4,17,18],environ:1,error:[0,19],evalu:0,event:[2,4,17,18],exampl:[0,4],exec:11,execut:1,exist:[2,4,6,7,8,10,17,18],explicit:[2,4,17,18],exponenti:0,express:0,extract:0,factori:13,fals:[0,2,3,4,7,10,17,18],fan:4,fan_in_net:4,fan_out_net:4,file:[1,5,14,19,20,22],file_nam:[14,22],filter:[4,17,18,19],find:[1,7,8],first:[0,4,17,18],fit:10,forc:[2,4,17,18],format:14,found:0,framework:22,free:19,from:[0,2,4,5,6,7,8,17,18,19,20],from_str:0,func:4,gate:[1,3,10,13,17,18,19,20],gate_id:[10,19],gate_librari:20,gate_library_fil:20,gate_typ:[4,5,8,18,19],gatelibrari:[5,19,20],gatetyp:[4,5,6,7,8,19],gatetypelut:7,gatetypesequenti:8,gener:[0,7,8,11],get:[0,1,2,4,5,6,7,8,10,15,17,18,19,22],get_base_directori:1,get_base_typ:[6,7,8],get_binary_directori:1,get_boolean_funct:[4,6,7,8],get_cli_opt:14,get_clock_pin:8,get_config_data_categori:7,get_config_data_identifi:7,get_data_by_kei:[2,4,17,18],get_default_log_directori:1,get_design_nam:19,get_destin:18,get_device_nam:19,get_fan_in_endpoint:4,get_fan_in_net:4,get_fan_out_endpoint:4,get_fan_out_net:4,get_gat:[3,17,18,19],get_gate_by_id:[17,19],get_gate_librari:19,get_gate_library_directori:1,get_gate_typ:5,get_global_input_net:19,get_global_output_net:19,get_gnd_gat:19,get_gnd_gate_typ:5,get_id:[4,17,18,19],get_includ:5,get_init_data_categori:8,get_init_data_identifi:8,get_input_filenam:19,get_input_net:17,get_input_pin:[4,6,7,8],get_input_pin_group:[6,7,8],get_input_port_nam:17,get_internal_net:17,get_inverted_state_output_pin:8,get_library_directori:1,get_loc:4,get_location_i:4,get_location_x:4,get_modul:[4,19],get_module_by_id:19,get_nam:[4,5,6,7,8,15,17,18],get_net:[3,19],get_net_by_id:19,get_netlist:[4,17],get_num_of_destin:18,get_num_of_sourc:18,get_output_from_init_string_pin:7,get_output_net:17,get_output_pin:[4,6,7,8],get_output_pin_group:[6,7,8],get_output_port_nam:17,get_parent_modul:17,get_path:5,get_pin:3,get_plugin_directori:1,get_plugin_inst:22,get_plugin_nam:22,get_predecessor:4,get_selected_g:10,get_selected_gate_id:10,get_selected_item:10,get_selected_item_id:10,get_selected_modul:10,get_selected_module_id:10,get_selected_net:10,get_selected_net_id:10,get_set_reset_behavior:8,get_share_directori:1,get_sourc:18,get_state_output_pin:8,get_submodul:17,get_successor:4,get_top_modul:19,get_truth_t:0,get_typ:[4,17],get_unique_gate_id:19,get_unique_module_id:19,get_unique_net_id:19,get_unique_predecessor:4,get_unique_successor:4,get_user_config_directori:1,get_user_share_directori:1,get_vari:0,get_vcc_gat:19,get_vcc_gate_typ:5,get_vers:15,given:[0,4,17],global:[4,17,18,19],global_input_net:19,global_output_net:19,gnd:[4,5,19],gnd_gate:19,gnd_gate_typ:5,graph:[10,13],group:[6,7,8],group_nam:[6,7,8],gui:[2,4,12,13,17,18],guiapi:10,guiplugininterfac:11,hal:[1,3,4,6,7,8,13,14,19,20,22],hal_base_path:1,hal_fil:20,hal_gui:[10,16],hal_path:[1,5,14,19,20,22],hal_pi:[0,1,2,3,4,5,6,7,8,10,11,14,15,17,18,19,20,21,22],halpath:[1,14,19,20,21,22],handl:[0,6,7,8],hardwar:19,has:[8,17,18],has_loc:4,hdl:[1,13,20],hdl_file:20,hdl_writer_manag:14,help:[0,3,5],home:1,i_bas:15,identifi:[7,8,19],ids:10,inc:5,includ:[0,4,5,17,18,19],index:[6,7,8,16],index_to_pin:[6,7,8],indic:[6,7,8],indirect:17,info:[2,4,17,18],inform:[4,5,6,7,8,17,18,19],init:[7,8],init_data_categori:8,init_data_identifi:8,initi:[3,5,7],input:[0,4,6,7,8,14,17,18,19],input_filenam:19,input_net:17,input_pin:[4,6,7,8],input_port_nam:17,insid:17,instal:1,instanc:0,intend:0,interfac:[13,14,22],intern:[6,7,8,17],internal_net:17,interpret:[0,1],invalid:19,invert:8,is_a_destin:18,is_a_sourc:18,is_config_data_ascending_ord:7,is_constant_on:0,is_constant_zero:0,is_destin:3,is_destination_pin:3,is_dnf:0,is_empti:0,is_gate_in_netlist:19,is_global_input_net:[18,19],is_global_output_net:[18,19],is_gnd_gat:[4,19],is_module_in_netlist:19,is_net_in_netlist:19,is_sourc:3,is_source_pin:3,is_unrout:18,is_vcc_gat:[4,19],item:10,its:[1,4,17,18,19],just:0,kei:[2,4,17,18],known:0,kwarg:[0,4,10,18,19,20,21],lambda:[4,17,19],latch:[6,7,8],layout:4,least:17,leav:[0,4,18],level:[2,4,17,18],librari:[1,13,19,20],like:4,line:14,list:[0,1,2,4,5,6,7,8,10,14,17,18,19,20,22],load:[20,22],load_all_plugin:22,load_netlist:20,local:1,locat:4,location_i:4,location_x:4,log:[1,2,4,17,18],log_with_info_level:[2,4,17,18],logic:0,look:17,lut:[6,8,13],mai:17,manag:13,map:[0,4,6,7,8,17],mark:[4,18,19],mark_global_input_net:[18,19],mark_global_output_net:[18,19],mark_gnd_gat:[4,19],mark_vcc_gat:[4,19],match:[0,20],matter:18,mccluskei:0,member:[0,6,7,8],might:0,modifi:10,modul:[4,10,13,16,19],module_id:10,move:17,multipl:[6,7,8],must:0,name:[0,4,5,6,7,8,15,17,18,19,20,22],navigate_to_select:10,necessari:5,neg:4,net:[3,4,10,13,17,19],net_id:[10,19],netlist:[2,4,11,13,14,17,18],netlistfactori:20,new_par:17,new_variable_nam:0,next:19,next_stat:8,none:[0,4,5,6,7,8,10,17,18,19,21],num_of_destin:18,num_of_sourc:18,number:[0,18],object:[1,5,6,7,8,11,17],old:[0,17],old_variable_nam:0,one:[0,4,17],onli:4,only_custom_funct:4,oper:0,optim:0,option:[14,17,19],oputput:7,order:[0,7],ordered_vari:0,other:[0,17],otherwis:[0,1,3,4,7],out:4,output:[0,4,6,7,8,17,18,19],output_from_init_string_pin:7,output_net:17,output_pin:[4,6,7,8],output_port_nam:17,outsid:17,overload:[0,4,10,18,19,20,21],page:16,pair:4,param:[0,4,10,18,19,20],paramet:[0,1,2,4,5,6,7,8,11,14,17,18,19,20,22],parent:[1,4,17,19],parent_modul:17,pars:0,part:0,pass:10,path:[1,5,13,19,20,22],physic:4,pin:[3,4,6,7,8,18],pin_group:[6,7,8],pin_nam:[6,7,8],place:0,plain:0,plugin:[1,13],plugin_manag:22,plugin_nam:22,port:[4,17],port_nam:17,posit:[4,10],pre:20,preced:0,predecessor:4,previou:[10,17],problemat:0,process:17,programopt:14,provid:1,pybind11_builtin:[7,8],pybind11_object:[7,8],python3:1,quin:0,recurs:17,recus:17,regard:[4,17],regist:19,rel:1,releas:22,remov:[0,17,18,19],remove_destin:18,remove_g:17,remove_sourc:18,remove_unknown_vari:0,renam:0,repres:[0,6,7,8,19],represent:0,reserv:19,reset:[4,8],resolv:0,resourc:22,result:0,rout:18,rtype:[0,4,18,19,20],run:11,runtim:0,rytp:8,sb1:8,sb2:8,scroll:10,search:[1,16,17,22],see:[3,5],select:10,select_g:10,select_modul:10,select_net:10,self:[0,2,3,4,5,6,7,8,10,11,15,17,18,19,21],sequenti:13,serial:5,set:[0,2,4,7,8,14,17,18,19,22],set_boolean_funct:4,set_config_data_ascending_ord:7,set_config_data_categori:7,set_config_data_identifi:7,set_data:[2,4,17,18],set_design_nam:19,set_device_nam:19,set_id:19,set_init_data_categori:8,set_init_data_identifi:8,set_input_filenam:19,set_input_port_nam:17,set_loc:4,set_location_i:4,set_location_x:4,set_nam:[4,17,18],set_output_port_nam:17,set_parent_modul:17,set_set_reset_behavior:8,set_typ:17,setresetbehavior:8,shall:0,share:1,shorthand:0,show:[8,10],signal:8,signatur:[3,5],sinc:0,singl:[0,19,22],some:17,sourc:[1,3,17,18],source_fil:1,specif:[0,4,6,7,8,20],specifi:[2,4,6,7,8,17,18,19,22],state:8,store:[2,4,17,18],str:[0,2,3,4,5,6,7,8,14,15,17,18,19,20,21,22],string:[0,7,8,17],structur:0,submodul:17,substitut:0,succ:[18,19],success:[2,4,11,14,17,18,19,22],successor:4,suppli:0,support:0,tabl:0,take:0,target:[14,19],term:0,test:0,therefor:17,thi:[0,4,17,18],to_dnf:0,toggl:8,too:17,top:[17,19],top_modul:19,trace:[2,4,17,18],truth:0,tupl:[2,4,8,10,17,18],type:[0,1,2,3,4,5,10,11,13,14,15,17,18,19,20,22],unchang:0,undefin:[0,8],underli:[19,20],uniqu:[4,17,18,19,22],unique_predecessor:4,unique_successor:4,unix:1,unload_all_plugin:22,unmark:[4,18,19],unmark_global_input_net:[18,19],unmark_global_output_net:[18,19],unmark_gnd_g:[4,19],unmark_vcc_g:[4,19],unoccupi:19,unrout:18,usabl:0,use:[1,5,8],used:[0,4,7,8],user:1,usual:4,util:13,valid:4,valu:[0,2,4,8,17,18,19],value_data_typ:[2,4,17,18],variabl:[0,1],variable_nam:0,varibl:0,vcc:[4,5,19],vcc_gate:19,vcc_gate_typ:5,vector:[0,1,6,7,8,18,20],verilog:14,version:15,vhdl:[5,14],via:[4,19],view:10,walk:0,warn:0,well:[17,19],were:4,wether:19,when:[0,8],where:1,whether:[0,3,4,17,18,19],which:[0,4,7,8,10,19],which_pin:4,write:14,writer:13,xor:0,yet:[2,4,17,18],you:[17,19],zero:[0,8,19],zoom:10},titles:["Boolean Function","Core Utils","Data Container","Endpoint","Gate","Gate Library","Gate Type","Gate Type LUT","Gate Type Sequential","Graph Algorithm","GUI API","GUI Plugin Interface","hal_gui Documentation","hal_py Documentation","HDL Writer Manager","Base Plugin Interface","hal_py Documentation","Module","Net","Netlist","Netlist Factory","HAL Path","Plugin Manager"],titleterms:{"boolean":0,"function":0,algorithm:9,api:10,base:15,contain:2,core:1,data:2,document:[12,13,16],endpoint:3,factori:20,gate:[4,5,6,7,8],graph:9,gui:[10,11],hal:21,hal_gui:12,hal_pi:[13,16],hdl:14,indic:16,interfac:[11,15],librari:5,lut:7,manag:[14,22],modul:17,net:18,netlist:[19,20],path:21,plugin:[11,15,22],sequenti:8,tabl:16,type:[6,7,8],util:1,writer:14}})