#pragma once
#include <beowulf/plugins/block_api/block_api_objects.hpp>

#include <beowulf/protocol/types.hpp>
#include <beowulf/protocol/transaction.hpp>
#include <beowulf/protocol/block_header.hpp>

#include <beowulf/plugins/json_rpc/utility.hpp>

namespace beowulf { namespace plugins { namespace block_api {

/* get_block_header */

struct get_block_header_args
{
   uint32_t block_num;
};

struct get_block_header_return
{
   optional< block_header > header;
};

/* get_block */
struct get_block_args
{
   uint32_t block_num;
};

struct get_block_return
{
   optional< api_signed_block_object > block;
};

} } } // beowulf::block_api

FC_REFLECT( beowulf::plugins::block_api::get_block_header_args,
   (block_num) )

FC_REFLECT( beowulf::plugins::block_api::get_block_header_return,
   (header) )

FC_REFLECT( beowulf::plugins::block_api::get_block_args,
   (block_num) )

FC_REFLECT( beowulf::plugins::block_api::get_block_return,
   (block) )

