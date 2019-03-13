#include <appbase/application.hpp>
#include <boost/preprocessor/seq/for_each.hpp>

#include <beowulf/manifest/plugins.hpp>

#include <beowulf/plugins/webserver/webserver_plugin.hpp>

#include <beowulf/plugins/account_history/account_history_plugin.hpp>

#include <beowulf/plugins/account_by_key/account_by_key_plugin.hpp>

#include <beowulf/plugins/witness/witness_plugin.hpp>

#include <beowulf/plugins/p2p/p2p_plugin.hpp>

#include <beowulf/plugins/statsd/statsd_plugin.hpp>

#include <beowulf/plugins/smt_test/smt_test_plugin.hpp>

#include <beowulf/plugins/chain/chain_plugin.hpp>

#include <beowulf/plugins/block_api/block_api_plugin.hpp>

#include <beowulf/plugins/network_broadcast_api/network_broadcast_api_plugin.hpp>

#include <beowulf/plugins/database_api/database_api_plugin.hpp>

#include <beowulf/plugins/account_by_key_api/account_by_key_api_plugin.hpp>

#include <beowulf/plugins/debug_node_api/debug_node_api_plugin.hpp>

#include <beowulf/plugins/condenser_api/condenser_api_plugin.hpp>

#include <beowulf/plugins/rc_api/rc_api_plugin.hpp>

#include <beowulf/plugins/chain_api/chain_api_plugin.hpp>

#include <beowulf/plugins/account_history_api/account_history_api_plugin.hpp>

#include <beowulf/plugins/account_history_rocksdb/account_history_rocksdb_plugin.hpp>

#include <beowulf/plugins/block_data_export/block_data_export_plugin.hpp>

#include <beowulf/plugins/rc/rc_plugin.hpp>

#include <beowulf/plugins/stats_export/stats_export_plugin.hpp>

#include <beowulf/plugins/block_log_info/block_log_info_plugin.hpp>

#include <beowulf/plugins/debug_node/debug_node_plugin.hpp>


namespace beowulf { namespace plugins {

void register_plugins()
{
   appbase::app().register_plugin< beowulf::plugins::webserver::webserver_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::account_history::account_history_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::account_by_key::account_by_key_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::witness::witness_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::p2p::p2p_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::statsd::statsd_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::smt_test::smt_test_plugin >();

   appbase::app().register_plugin< beowulf::plugins::chain::chain_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::block_api::block_api_plugin >();

   appbase::app().register_plugin< beowulf::plugins::network_broadcast_api::network_broadcast_api_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::database_api::database_api_plugin >();

   appbase::app().register_plugin< beowulf::plugins::account_by_key::account_by_key_api_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::debug_node::debug_node_api_plugin >();

   appbase::app().register_plugin< beowulf::plugins::condenser_api::condenser_api_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::rc::rc_api_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::chain::chain_api_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::account_history::account_history_api_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::account_history_rocksdb::account_history_rocksdb_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::block_data_export::block_data_export_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::rc::rc_plugin >();

   appbase::app().register_plugin< beowulf::plugins::stats_export::stats_export_plugin >();

   appbase::app().register_plugin< beowulf::plugins::block_log_info::block_log_info_plugin >();
   
   appbase::app().register_plugin< beowulf::plugins::debug_node::debug_node_plugin >();
   
}

} }