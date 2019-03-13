#pragma once
#include <beowulf/protocol/required_automated_actions.hpp>

#include <beowulf/chain/beowulf_object_types.hpp>

#include <boost/multi_index/composite_key.hpp>

namespace beowulf { namespace chain {

using beowulf::protocol::optional_automated_action;

class pending_optional_action_object : public object< pending_optional_action_object_type, pending_optional_action_object >
{
   pending_optional_action_object() = delete;

   public:
      template< typename Constructor, typename Allocator >
      pending_optional_action_object( Constructor&& c, allocator< Allocator > a )
      {
         c( *this );
      }

      id_type           id;

      optional_automated_action  action;
};

typedef multi_index_container<
   pending_optional_action_object,
   indexed_by<
      ordered_unique< tag< by_id >, member< pending_optional_action_object, pending_optional_action_id_type, &pending_optional_action_object::id > >
   >,
   allocator< pending_optional_action_object >
> pending_optional_action_index;

} } //beowulf::chain

FC_REFLECT( beowulf::chain::pending_optional_action_object,
            (id)(action) )
CHAINBASE_SET_INDEX_TYPE( beowulf::chain::pending_optional_action_object, beowulf::chain::pending_optional_action_index )
