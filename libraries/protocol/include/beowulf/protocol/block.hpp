#pragma once
#include <beowulf/protocol/block_header.hpp>
#include <beowulf/protocol/transaction.hpp>

namespace beowulf { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // beowulf::protocol

FC_REFLECT_DERIVED( beowulf::protocol::signed_block, (beowulf::protocol::signed_block_header), (transactions) )
