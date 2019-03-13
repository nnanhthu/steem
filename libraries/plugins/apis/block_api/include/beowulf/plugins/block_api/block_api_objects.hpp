#pragma once
#include <beowulf/chain/account_object.hpp>
#include <beowulf/chain/block_summary_object.hpp>
#include <beowulf/chain/comment_object.hpp>
#include <beowulf/chain/global_property_object.hpp>
#include <beowulf/chain/history_object.hpp>
#include <beowulf/chain/beowulf_objects.hpp>
#include <beowulf/chain/transaction_object.hpp>
#include <beowulf/chain/witness_objects.hpp>
#include <beowulf/chain/database.hpp>

namespace beowulf { namespace plugins { namespace block_api {

using namespace beowulf::chain;

struct api_signed_block_object : public signed_block
{
   api_signed_block_object( const signed_block& block ) : signed_block( block )
   {
      block_id = id();
      signing_key = signee();
      transaction_ids.reserve( transactions.size() );
      for( const signed_transaction& tx : transactions )
         transaction_ids.push_back( tx.id() );
   }
   api_signed_block_object() {}

   block_id_type                 block_id;
   public_key_type               signing_key;
   vector< transaction_id_type > transaction_ids;
};

} } } // beowulf::plugins::database_api

FC_REFLECT_DERIVED( beowulf::plugins::block_api::api_signed_block_object, (beowulf::protocol::signed_block),
                     (block_id)
                     (signing_key)
                     (transaction_ids)
                  )
