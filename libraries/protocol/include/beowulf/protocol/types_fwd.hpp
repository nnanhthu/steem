#pragma once
#include <cstdint>
#include <fc/uint128.hpp>

namespace fc {
class variant;
} // fc

namespace beowulf { namespace protocol {
template< typename Storage = fc::uint128 >
class fixed_string_impl;

class asset_symbol_type;
class legacy_sbd_asset_symbol_type;
struct legacy_sbd_asset;
} } // beowulf::protocol

namespace fc { namespace raw {

template< typename Stream, typename Storage >
inline void pack( Stream& s, const beowulf::protocol::fixed_string_impl< Storage >& u );
template< typename Stream, typename Storage >
inline void unpack( Stream& s, beowulf::protocol::fixed_string_impl< Storage >& u, uint32_t depth = 0 );

template< typename Stream >
inline void pack( Stream& s, const beowulf::protocol::asset_symbol_type& sym );
template< typename Stream >
inline void unpack( Stream& s, beowulf::protocol::asset_symbol_type& sym, uint32_t depth = 0 );

template< typename Stream >
inline void pack( Stream& s, const beowulf::protocol::legacy_sbd_asset_symbol_type& sym );
template< typename Stream >
inline void unpack( Stream& s, beowulf::protocol::legacy_sbd_asset_symbol_type& sym, uint32_t depth = 0 );

} // raw

template< typename Storage >
inline void to_variant( const beowulf::protocol::fixed_string_impl< Storage >& s, fc::variant& v );
template< typename Storage >
inline void from_variant( const variant& v, beowulf::protocol::fixed_string_impl< Storage >& s );

inline void to_variant( const beowulf::protocol::asset_symbol_type& sym, fc::variant& v );

inline void from_variant( const fc::variant& v, beowulf::protocol::legacy_sbd_asset& leg );
inline void to_variant( const beowulf::protocol::legacy_sbd_asset& leg, fc::variant& v );

} // fc
