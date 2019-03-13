#pragma once

#include <fc/container/flat.hpp>
#include <beowulf/protocol/operations.hpp>
#include <beowulf/protocol/transaction.hpp>

#include <fc/string.hpp>

namespace beowulf { namespace app {

using namespace fc;

void operation_get_impacted_accounts(
   const beowulf::protocol::operation& op,
   fc::flat_set<protocol::account_name_type>& result );

void transaction_get_impacted_accounts(
   const beowulf::protocol::transaction& tx,
   fc::flat_set<protocol::account_name_type>& result
   );

} } // beowulf::app
