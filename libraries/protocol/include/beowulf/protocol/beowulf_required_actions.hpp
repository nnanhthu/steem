#pragma once
#include <beowulf/protocol/base.hpp>
#include <beowulf/protocol/block_header.hpp>
#include <beowulf/protocol/asset.hpp>
#include <beowulf/protocol/validation.hpp>
#include <beowulf/protocol/legacy_asset.hpp>

#include <fc/crypto/equihash.hpp>

namespace beowulf { namespace protocol {

   struct required_action : public base_operation
   {
      account_name_type account;

      void validate()const;
      void get_required_active_authorities( flat_set<account_name_type>& a )const{ a.insert(account); }
   };

} } // beowulf::protocol

FC_REFLECT( beowulf::protocol::required_action, (account) )
