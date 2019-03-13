#pragma once

#include <beowulf/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace beowulf { namespace app {
   struct api_context;
} }

namespace beowulf { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const beowulf::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // beowulf::account_statistics

FC_API( beowulf::account_statistics::account_statistics_api, )