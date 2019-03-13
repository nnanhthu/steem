#pragma once

#include <beowulf/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

namespace beowulf { namespace protocol {
struct signed_transaction;
} } // beowulf::protocol

namespace beowulf { namespace plugins { namespace rc {

using beowulf::protocol::account_name_type;
using beowulf::protocol::signed_transaction;

account_name_type get_resource_user( const signed_transaction& tx );

} } } // beowulf::plugins::rc
