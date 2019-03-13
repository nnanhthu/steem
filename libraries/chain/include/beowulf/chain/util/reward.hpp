#pragma once

#include <beowulf/chain/util/asset.hpp>
#include <beowulf/chain/beowulf_objects.hpp>

#include <beowulf/protocol/asset.hpp>
#include <beowulf/protocol/config.hpp>
#include <beowulf/protocol/types.hpp>
#include <beowulf/protocol/misc_utilities.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace beowulf { namespace chain { namespace util {

using beowulf::protocol::asset;
using beowulf::protocol::price;
using beowulf::protocol::share_type;

using fc::uint128_t;

//struct comment_reward_context
//{
//   share_type rshares;
//   uint16_t   reward_weight = 0;
//   asset      max_sbd;
//   uint128_t  total_reward_shares2;
//   asset      total_reward_fund_beowulf;
//   price      current_beowulf_price;
//   protocol::curve_id   reward_curve = protocol::quadratic;
//   uint128_t  content_constant = 0; // BEOWULF_CONTENT_CONSTANT_HF0;
//};

//uint64_t get_rshare_reward( const comment_reward_context& ctx );

//inline uint128_t get_content_constant_s()
//{
//   return 0;// BEOWULF_CONTENT_CONSTANT_HF0; // looking good for posters
//}

//uint128_t evaluate_reward_curve( const uint128_t& rshares, const protocol::curve_id& curve = protocol::quadratic, const uint128_t& content_constant = 0 );
//
//inline bool is_comment_payout_dust( const price& p, uint64_t beowulf_payout )
//{
//   return to_sbd( p, asset( beowulf_payout, BEOWULF_SYMBOL ) ) < BEOWULF_MIN_PAYOUT_SBD;
//}

} } } // beowulf::chain::util

//FC_REFLECT( beowulf::chain::util::comment_reward_context,
//   (rshares)
//   (reward_weight)
//   (max_sbd)
//   (total_reward_shares2)
//   (total_reward_fund_beowulf)
//   (current_beowulf_price)
//   (reward_curve)
//   (content_constant)
//   )
