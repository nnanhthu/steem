#pragma once

#include <beowulf/protocol/asset.hpp>

namespace beowulf { namespace chain { namespace util {

using beowulf::protocol::asset;
using beowulf::protocol::price;

inline asset to_sbd( const price& p, const asset& beowulf )
{
   FC_ASSERT( beowulf.symbol == BEOWULF_SYMBOL );
   if( p.is_null() )
      return asset( 0, SBD_SYMBOL );
   return beowulf * p;
}

inline asset to_beowulf( const price& p, const asset& sbd )
{
   FC_ASSERT( sbd.symbol == SBD_SYMBOL );
   if( p.is_null() )
      return asset( 0, BEOWULF_SYMBOL );
   return sbd * p;
}

} } }
