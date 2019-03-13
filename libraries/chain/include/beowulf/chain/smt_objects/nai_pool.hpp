#pragma once
#include <beowulf/chain/database.hpp>
#include <beowulf/protocol/asset_symbol.hpp>

//#ifdef BEOWULF_ENABLE_SMT

namespace beowulf { namespace chain {

   void replenish_nai_pool( database& db );
   void remove_from_nai_pool( database &db, const asset_symbol_type& a );

} } // beowulf::chain

//#endif
