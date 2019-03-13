#pragma once

#include <beowulf/protocol/block.hpp>

namespace beowulf { namespace chain {

struct transaction_notification
{
   transaction_notification( const beowulf::protocol::signed_transaction& tx ) : transaction(tx)
   {
      transaction_id = tx.id();
   }

   beowulf::protocol::transaction_id_type          transaction_id;
   const beowulf::protocol::signed_transaction&    transaction;
};

} }
