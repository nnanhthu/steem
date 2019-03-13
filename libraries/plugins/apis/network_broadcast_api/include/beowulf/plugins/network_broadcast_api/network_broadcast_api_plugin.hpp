#pragma once
#include <beowulf/plugins/json_rpc/json_rpc_plugin.hpp>
#include <beowulf/plugins/chain/chain_plugin.hpp>
#include <beowulf/plugins/p2p/p2p_plugin.hpp>
#include <beowulf/plugins/rc/rc_plugin.hpp>

#include <appbase/application.hpp>

#define BEOWULF_NETWORK_BROADCAST_API_PLUGIN_NAME "network_broadcast_api"

namespace beowulf { namespace plugins { namespace network_broadcast_api {

using namespace appbase;

class network_broadcast_api_plugin : public appbase::plugin< network_broadcast_api_plugin >
{
public:
   APPBASE_PLUGIN_REQUIRES(
      (beowulf::plugins::json_rpc::json_rpc_plugin)
      (beowulf::plugins::rc::rc_plugin)
      (beowulf::plugins::chain::chain_plugin)
      (beowulf::plugins::p2p::p2p_plugin)
   )

   network_broadcast_api_plugin();
   virtual ~network_broadcast_api_plugin();

   static const std::string& name() { static std::string name = BEOWULF_NETWORK_BROADCAST_API_PLUGIN_NAME; return name; }

   virtual void set_program_options( options_description& cli, options_description& cfg ) override;
   virtual void plugin_initialize( const variables_map& options ) override;
   virtual void plugin_startup() override;
   virtual void plugin_shutdown() override;

   std::shared_ptr< class network_broadcast_api > api;
};

} } } // beowulf::plugins::network_broadcast_api
