#pragma once

//#ifdef BEOWULF_ENABLE_SMT

#include <fc/optional.hpp>
#include <beowulf/chain/database.hpp>
#include <beowulf/chain/smt_objects/smt_token_object.hpp>
#include <beowulf/protocol/asset_symbol.hpp>

namespace beowulf { namespace chain { namespace util { namespace smt {

const smt_token_object* find_token( const database& db, uint32_t nai );
const smt_token_object* find_token( const database& db, asset_symbol_type symbol, bool precision_agnostic = false );
//fc::optional< time_point_sec > last_emission_time( const database& db, const asset_symbol_type& symbol );

} } } } // beowulf::chain::util::smt

//#endif
