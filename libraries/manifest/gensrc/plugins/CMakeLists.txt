
add_library( beowulf_plugins
   mf_plugins.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/beowulf/manifest/plugins.hpp
)

target_link_libraries( beowulf_plugins appbase fc

   webserver_plugin

   account_history_plugin

   account_by_key_plugin

   witness_plugin

   p2p_plugin

   statsd_plugin

   smt_test_plugin

   chain_plugin

   block_api_plugin

   network_broadcast_api_plugin

   database_api_plugin

   account_by_key_api_plugin

   debug_node_api_plugin

   condenser_api_plugin

   rc_api_plugin

   chain_api_plugin

   account_history_api_plugin

   account_history_rocksdb_plugin

   block_data_export_plugin

   rc_plugin

   stats_export_plugin

   block_log_info_plugin

   debug_node_plugin

)

target_include_directories( beowulf_plugins
   PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
   )

INSTALL( TARGETS
   beowulf_plugins

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)