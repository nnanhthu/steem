#pragma once

#include <beowulf/protocol/types.hpp>

#include <fc/int_array.hpp>
#include <fc/reflect/reflect.hpp>
#include <vector>

#define BEOWULF_NUM_RESOURCE_TYPES     5

namespace beowulf { namespace protocol {
struct signed_transaction;
} } // beowulf::protocol

namespace beowulf { namespace plugins { namespace rc {

enum rc_resource_types
{
   resource_history_bytes,
   resource_new_accounts,
   resource_market_bytes,
   resource_state_bytes,
   resource_execution_time
};

typedef fc::int_array< int64_t, BEOWULF_NUM_RESOURCE_TYPES > resource_count_type;

struct count_resources_result
{
   resource_count_type                            resource_count;
};

void count_resources(
   const beowulf::protocol::signed_transaction& tx,
   count_resources_result& result );

} } } // beowulf::plugins::rc

FC_REFLECT_ENUM( beowulf::plugins::rc::rc_resource_types,
    (resource_history_bytes)
    (resource_new_accounts)
    (resource_market_bytes)
    (resource_state_bytes)
    (resource_execution_time)
   )

FC_REFLECT( beowulf::plugins::rc::count_resources_result,
   (resource_count)
)

FC_REFLECT_TYPENAME( beowulf::plugins::rc::resource_count_type )
