#pragma once
#include <beowulf/protocol/required_automated_actions.hpp>

#include <beowulf/chain/beowulf_object_types.hpp>

#include <boost/multi_index/composite_key.hpp>

namespace beowulf { namespace chain {

using beowulf::protocol::required_automated_action;

class pending_required_action_object : public object< pending_required_action_object_type, pending_required_action_object >
{
   pending_required_action_object() = delete;

   public:
      template< typename Constructor, typename Allocator >
      pending_required_action_object( Constructor&& c, allocator< Allocator > a )
      {
         c( *this );
      }

      id_type           id;

      required_automated_action  action;
};

typedef multi_index_container<
   pending_required_action_object,
   indexed_by<
      ordered_unique< tag< by_id >, member< pending_required_action_object, pending_required_action_id_type, &pending_required_action_object::id > >
   >,
   allocator< pending_required_action_object >
> pending_required_action_index;

} } //beowulf::chain

FC_REFLECT( beowulf::chain::pending_required_action_object,
            (id)(action) )
CHAINBASE_SET_INDEX_TYPE( beowulf::chain::pending_required_action_object, beowulf::chain::pending_required_action_index )
