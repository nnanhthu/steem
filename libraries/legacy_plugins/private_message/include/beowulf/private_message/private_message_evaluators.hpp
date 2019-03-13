#pragma once

#include <beowulf/chain/evaluator.hpp>

#include <beowulf/private_message/private_message_operations.hpp>
#include <beowulf/private_message/private_message_plugin.hpp>

namespace beowulf { namespace private_message {

BEOWULF_DEFINE_PLUGIN_EVALUATOR( private_message_plugin, beowulf::private_message::private_message_plugin_operation, private_message )

} }
