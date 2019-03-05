#pragma once

#include <steem/protocol/asset.hpp>

#define SBD_SYMBOL_LEGACY_SER_1   (uint64_t(1) | (SBD_SYMBOL_U64 << 8))
#define SBD_SYMBOL_LEGACY_SER_2   (uint64_t(2) | (SBD_SYMBOL_U64 << 8))
#define SBD_SYMBOL_LEGACY_SER_3   (uint64_t(3) | (SBD_SYMBOL_U64 << 8))
#define SBD_SYMBOL_LEGACY_SER_4   (uint64_t(5) | (uint64_t('0') << 8) | (uint64_t('.') << 16) | (uint64_t('0') << 24) | (uint64_t('0') << 32) | (uint64_t('0') << 40) | (uint64_t('0') << 48) | (uint64_t('1') << 56))
#define SBD_SYMBOL_LEGACY_SER_5   (uint64_t(5) | (uint64_t('6') << 8) | (uint64_t('.') << 16) | (uint64_t('0') << 24) | (uint64_t('0') << 32) | (uint64_t('0') << 40) | (uint64_t('0') << 48) | (uint64_t('0') << 56))

namespace steem { namespace protocol {

class legacy_sbd_asset_symbol_type
{
   public:
      legacy_sbd_asset_symbol_type() {}

      bool is_canon()const
      {   return ( ser == SBD_SYMBOL_SER );    }

      uint64_t ser = SBD_SYMBOL_SER;
};

struct legacy_sbd_asset
{
   public:
      legacy_sbd_asset() {}

      template< bool force_canon >
      asset to_asset()const
      {
         if( force_canon )
         {
            FC_ASSERT( symbol.is_canon(), "Must use canonical W symbol serialization" );
         }
         return asset( amount, SBD_SYMBOL );
      }

      static legacy_sbd_asset from_amount( share_type amount )
      {
         legacy_sbd_asset leg;
         leg.amount = amount;
         return leg;
      }

      static legacy_sbd_asset from_asset( const asset& a )
      {
         FC_ASSERT( a.symbol == SBD_SYMBOL );
         return from_amount( a.amount );
      }

      share_type                       amount;
      legacy_sbd_asset_symbol_type     symbol;
};

} }

namespace fc { namespace raw {

template< typename Stream >
inline void pack( Stream& s, const steem::protocol::legacy_sbd_asset_symbol_type& sym )
{
   switch( sym.ser )
   {
      case SBD_SYMBOL_LEGACY_SER_1:
      case SBD_SYMBOL_LEGACY_SER_2:
      case SBD_SYMBOL_LEGACY_SER_3:
      case SBD_SYMBOL_LEGACY_SER_4:
      case SBD_SYMBOL_LEGACY_SER_5:
         wlog( "pack legacy serialization ${s}", ("s", sym.ser) );
      case SBD_SYMBOL_SER:
         pack( s, sym.ser );
         break;
      default:
         FC_ASSERT( false, "Cannot serialize legacy symbol ${s}", ("s", sym.ser) );
   }
}

template< typename Stream >
inline void unpack( Stream& s, steem::protocol::legacy_sbd_asset_symbol_type& sym, uint32_t depth )
{
   //  994240:        "account_creation_fee": "0.1 STEEM"
   // 1021529:        "account_creation_fee": "10.0 STEEM"
   // 3143833:        "account_creation_fee": "3.000 STEEM"
   // 3208405:        "account_creation_fee": "2.000 STEEM"
   // 3695672:        "account_creation_fee": "3.00 STEEM"
   // 4338089:        "account_creation_fee": "0.00001 0.00001"
   // 4626205:        "account_creation_fee": "6.00000 6.00000"
   // 4632595:        "account_creation_fee": "6.00000 6.00000"
   depth++;
   uint64_t ser = 0;

   fc::raw::unpack( s, ser, depth );
   switch( ser )
   {
      case SBD_SYMBOL_LEGACY_SER_1:
      case SBD_SYMBOL_LEGACY_SER_2:
      case SBD_SYMBOL_LEGACY_SER_3:
      case SBD_SYMBOL_LEGACY_SER_4:
      case SBD_SYMBOL_LEGACY_SER_5:
         wlog( "unpack legacy serialization ${s}", ("s", ser) );
      case SBD_SYMBOL_SER:
         sym.ser = ser;
         break;
      default:
         FC_ASSERT( false, "Cannot deserialize legacy symbol ${s}", ("s", ser) );
   }
}

} // fc::raw

inline void to_variant( const steem::protocol::legacy_sbd_asset& leg, fc::variant& v )
{
   to_variant( leg.to_asset<false>(), v );
}

inline void from_variant( const fc::variant& v, steem::protocol::legacy_sbd_asset& leg )
{
   steem::protocol::asset a;
   from_variant( v, a );
   leg = steem::protocol::legacy_sbd_asset::from_asset( a );
}

template<>
struct get_typename< steem::protocol::legacy_sbd_asset_symbol_type >
{
   static const char* name()
   {
      return "steem::protocol::legacy_sbd_asset_symbol_type";
   }
};

} // fc

FC_REFLECT( steem::protocol::legacy_sbd_asset,
   (amount)
   (symbol)
   )
