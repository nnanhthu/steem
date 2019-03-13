#pragma once

#include <beowulf/protocol/beowulf_optional_actions.hpp>

#include <beowulf/protocol/operation_util.hpp>

namespace beowulf { namespace protocol {

   /** NOTE: do not change the order of any actions or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            optional_action
         > optional_automated_action;

} } // beowulf::protocol

BEOWULF_DECLARE_OPERATION_TYPE( beowulf::protocol::optional_automated_action );
FC_REFLECT_TYPENAME( beowulf::protocol::optional_automated_action );
