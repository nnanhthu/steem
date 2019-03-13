/*
 * Copyright (c) 2016 Steemit, Inc., and contributors.
 */
#pragma once
#include <beowulf/protocol/hardfork.hpp>

// WARNING!
// Every symbol defined here needs to be handled appropriately in get_config.cpp
// This is checked by get_config_check.sh called from Dockerfile

#ifdef IS_TEST_NET
#define BEOWULF_BLOCKCHAIN_VERSION              ( version(0, 21, 0) )

#define BEOWULF_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define BEOWULF_INIT_PUBLIC_KEY_STR             (std::string( beowulf::protocol::public_key_type(BEOWULF_INIT_PRIVATE_KEY.get_public_key()) ))
#define BEOWULF_CHAIN_ID (fc::sha256::hash("testnet"))
#define BEOWULF_ADDRESS_PREFIX                  "TST"

#define BEOWULF_GENESIS_TIME                    (fc::time_point_sec(1451606400))
#define BEOWULF_MINING_TIME                     (fc::time_point_sec(1451606400))
#define BEOWULF_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define BEOWULF_CASHOUT_WINDOW_SECONDS_PRE_HF12 (BEOWULF_CASHOUT_WINDOW_SECONDS)
#define BEOWULF_CASHOUT_WINDOW_SECONDS_PRE_HF17 (BEOWULF_CASHOUT_WINDOW_SECONDS)
#define BEOWULF_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define BEOWULF_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define BEOWULF_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define BEOWULF_UPVOTE_LOCKOUT_SECONDS          (60*5)    /// 5 minutes
#define BEOWULF_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define BEOWULF_MIN_ACCOUNT_CREATION_FEE          0
#define BEOWULF_MAX_ACCOUNT_CREATION_FEE          int64_t(1000000)

#define BEOWULF_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define BEOWULF_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define BEOWULF_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define BEOWULF_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1

#define BEOWULF_MIN_TRANSFER_FEE                  1
//#define BEOWULF_MAX_TRANSFER_FEE                  int64_t(10)
#define BEOWULF_INIT_SUPPLY                     (int64_t( 250 ) * int64_t( 1000000 ) * int64_t( 100000 ))

/// Allows to limit number of total produced blocks.
#define TESTNET_BLOCK_LIMIT                   (3000000)

#else // IS LIVE BEOWULF NETWORK

#define BEOWULF_BLOCKCHAIN_VERSION              ( version(0, 20, 8) )

#define BEOWULF_INIT_PUBLIC_KEY_STR             "BEO6GkXgEKTYc7gNv1GWJ5ZseyESHQnN7nr3rxdo5sBjzWQcdMyKy"
#define BLOCKCHAIN_NAME                       "BEOWULFBC"
#define BEOWULF_CHAIN_ID                        (fc::sha256::hash(BLOCKCHAIN_NAME))
//#define BEOWULF_CHAIN_ID                        fc::sha256("89c36da9bfecc0e7c8e7349d05845d7892f82055fa3a85affeff37f3792a2a60")
#define BEOWULF_ADDRESS_PREFIX                  "BEO"

#define BEOWULF_GENESIS_TIME                    (fc::time_point_sec(1458835200))
#define BEOWULF_MINING_TIME                     (fc::time_point_sec(1458838800))
//#define BEOWULF_CASHOUT_WINDOW_SECONDS_PRE_HF12 (60*60*24)    /// 1 day
//#define BEOWULF_CASHOUT_WINDOW_SECONDS_PRE_HF17 (60*60*12)    /// 12 hours
//#define BEOWULF_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
//#define BEOWULF_SECOND_CASHOUT_WINDOW           (60*60*24*30) /// 30 days
//#define BEOWULF_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24*14) /// 2 weeks
//#define BEOWULF_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
//#define BEOWULF_UPVOTE_LOCKOUT_SECONDS          (60*60*12)    /// 12 hours
//#define BEOWULF_UPVOTE_LOCKOUT_HF17             (fc::hours(12))

#define BEOWULF_MIN_ACCOUNT_CREATION_FEE           1
#define BEOWULF_MAX_ACCOUNT_CREATION_FEE           int64_t(1000000)

//#define BEOWULF_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
//#define BEOWULF_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define BEOWULF_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define BEOWULF_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 3186477

#define BEOWULF_INIT_SUPPLY                     (uint64_t(1000000000000000000ll))
#define SBD_INIT_SUPPLY                       (uint64_t(10000000000000000ll))

#define BEOWULF_MIN_TRANSFER_FEE           1
//#define BEOWULF_MAX_TRANSFER_FEE           int64_t(10)

#endif

#define VESTS_SYMBOL  (beowulf::protocol::asset_symbol_type::from_asset_num( BEOWULF_ASSET_NUM_VESTS ) )
#define BEOWULF_SYMBOL  (beowulf::protocol::asset_symbol_type::from_asset_num( BEOWULF_ASSET_NUM_BEOWULF ) )
#define SBD_SYMBOL    (beowulf::protocol::asset_symbol_type::from_asset_num( BEOWULF_ASSET_NUM_SBD ) )

#define BEOWULF_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( BEOWULF_BLOCKCHAIN_VERSION ) )

#define BEOWULF_BLOCK_INTERVAL                  10
#define BEOWULF_BLOCKS_PER_YEAR                 (365*24*60*60/BEOWULF_BLOCK_INTERVAL)
#define BEOWULF_BLOCKS_PER_DAY                  (24*60*60/BEOWULF_BLOCK_INTERVAL)
#define BEOWULF_START_VESTING_BLOCK             (BEOWULF_BLOCKS_PER_DAY * 7)
#define BEOWULF_START_MINER_VOTING_BLOCK        (BEOWULF_BLOCKS_PER_DAY * 30)

#define BEOWULF_INIT_MINER_NAME                 "initminer"
#define BEOWULF_NUM_INIT_MINERS                 1
#define BEOWULF_INIT_TIME                       (fc::time_point_sec());

#define BEOWULF_MAX_WITNESSES                   5

#define BEOWULF_MAX_VOTED_WITNESSES_HF0         3
#define BEOWULF_MAX_MINER_WITNESSES_HF0         1
#define BEOWULF_MAX_RUNNER_WITNESSES_HF0        1

#define BEOWULF_MAX_VOTED_WITNESSES_HF17        3
#define BEOWULF_MAX_MINER_WITNESSES_HF17        0
#define BEOWULF_MAX_RUNNER_WITNESSES_HF17       2

#define BEOWULF_HARDFORK_REQUIRED_WITNESSES     4 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define BEOWULF_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define BEOWULF_MAX_MEMO_SIZE                   128 //2048
#define BEOWULF_MAX_PROXY_RECURSION_DEPTH       4
#define BEOWULF_VESTING_WITHDRAW_INTERVALS_PRE_HF_16 104
#define BEOWULF_VESTING_WITHDRAW_INTERVALS      13
#define BEOWULF_VESTING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval
#define BEOWULF_MAX_WITHDRAW_ROUTES             10
//#define BEOWULF_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
//#define BEOWULF_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define BEOWULF_VOTING_MANA_REGENERATION_SECONDS (5*60*60*24) // 5 day
#define BEOWULF_MAX_VOTE_CHANGES                5
#define BEOWULF_REVERSE_AUCTION_WINDOW_SECONDS_HF6 (60*30) /// 30 minutes
#define BEOWULF_REVERSE_AUCTION_WINDOW_SECONDS_HF20 (60*15) /// 15 minutes
//#define BEOWULF_MIN_VOTE_INTERVAL_SEC           3
//#define BEOWULF_VOTE_DUST_THRESHOLD             (50000000)

//#define BEOWULF_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
//#define BEOWULF_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
//#define BEOWULF_MIN_REPLY_INTERVAL_HF20         (fc::seconds(3)) // 3 seconds
//#define BEOWULF_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
//#define BEOWULF_POST_WEIGHT_CONSTANT            (uint64_t(4*BEOWULF_100_PERCENT) * (4*BEOWULF_100_PERCENT))// (4*BEOWULF_100_PERCENT) -> 2 posts per 1 days, average 1 every 12 hours

#define BEOWULF_MAX_ACCOUNT_WITNESS_VOTES       30

#define BEOWULF_100_PERCENT                     10000
#define BEOWULF_1_PERCENT                       (BEOWULF_100_PERCENT/100)
//#define BEOWULF_DEFAULT_SBD_INTEREST_RATE       (10*BEOWULF_1_PERCENT) ///< 10% APR

#define BEOWULF_INFLATION_RATE_START_PERCENT    (978) // Fixes block 7,000,000 to 9.5%
#define BEOWULF_INFLATION_RATE_STOP_PERCENT     (95) // 0.95%
#define BEOWULF_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define BEOWULF_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
//#define BEOWULF_CONTENT_REWARD_PERCENT          (75*BEOWULF_1_PERCENT) //75% of inflation, 7.125% inflation
#define BEOWULF_VESTING_FUND_PERCENT            (50*BEOWULF_1_PERCENT) //(15*BEOWULF_1_PERCENT) //15% of inflation, 1.425% inflation

#define BEOWULF_MINER_PAY_PERCENT               (BEOWULF_1_PERCENT) // 1%
#define BEOWULF_MAX_RATION_DECAY_RATE           (1000000)

#define BEOWULF_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define BEOWULF_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
//#define BEOWULF_MAX_COMMENT_DEPTH_PRE_HF17      6
//#define BEOWULF_MAX_COMMENT_DEPTH               0xffff // 64k
//#define BEOWULF_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define BEOWULF_MAX_RESERVE_RATIO               (20000)

#define BEOWULF_CREATE_ACCOUNT_WITH_BEOWULF_MODIFIER 30
#define BEOWULF_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define BEOWULF_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define BEOWULF_MINING_REWARD                   asset( 1000, BEOWULF_SYMBOL )
#define BEOWULF_EQUIHASH_N                      140
#define BEOWULF_EQUIHASH_K                      6

#define BEOWULF_LIQUIDITY_TIMEOUT_SEC           (fc::seconds(60*60*24*7)) // After one week volume is set to 0
#define BEOWULF_MIN_LIQUIDITY_REWARD_PERIOD_SEC (fc::seconds(60)) // 1 minute required on books to receive volume
#define BEOWULF_LIQUIDITY_REWARD_PERIOD_SEC     (60*60)
#define BEOWULF_LIQUIDITY_REWARD_BLOCKS         (BEOWULF_LIQUIDITY_REWARD_PERIOD_SEC/BEOWULF_BLOCK_INTERVAL)
#define BEOWULF_MIN_LIQUIDITY_REWARD            (asset( 1000*BEOWULF_LIQUIDITY_REWARD_BLOCKS, BEOWULF_SYMBOL )) // Minumum reward to be paid out to liquidity providers
//#define BEOWULF_MIN_CONTENT_REWARD              BEOWULF_MINING_REWARD
//#define BEOWULF_MIN_CURATE_REWARD               BEOWULF_MINING_REWARD
#define BEOWULF_MIN_PRODUCER_REWARD             BEOWULF_MINING_REWARD
#define BEOWULF_MIN_POW_REWARD                  BEOWULF_MINING_REWARD

#define BEOWULF_ACTIVE_CHALLENGE_FEE            asset( 2000, BEOWULF_SYMBOL )
#define BEOWULF_OWNER_CHALLENGE_FEE             asset( 30000, BEOWULF_SYMBOL )
#define BEOWULF_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define BEOWULF_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

//#define BEOWULF_POST_REWARD_FUND_NAME           ("post")
//#define BEOWULF_COMMENT_REWARD_FUND_NAME        ("comment")
//#define BEOWULF_RECENT_RSHARES_DECAY_TIME_HF17    (fc::days(30))
//#define BEOWULF_RECENT_RSHARES_DECAY_TIME_HF19    (fc::days(15))
//#define BEOWULF_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))
// note, if redefining these constants make sure calculate_claims doesn't overflow

// 5ccc e802 de5f
// int(expm1( log1p( 1 ) / BLOCKS_PER_YEAR ) * 2**BEOWULF_APR_PERCENT_SHIFT_PER_BLOCK / 100000 + 0.5)
// we use 100000 here instead of 10000 because we end up creating an additional 9x for vesting
#define BEOWULF_APR_PERCENT_MULTIPLY_PER_BLOCK          ( (uint64_t( 0x5ccc ) << 0x20) \
                                                        | (uint64_t( 0xe802 ) << 0x10) \
                                                        | (uint64_t( 0xde5f )        ) \
                                                        )
// chosen to be the maximal value such that BEOWULF_APR_PERCENT_MULTIPLY_PER_BLOCK * 2**64 * 100000 < 2**128
#define BEOWULF_APR_PERCENT_SHIFT_PER_BLOCK             87

#define BEOWULF_APR_PERCENT_MULTIPLY_PER_ROUND          ( (uint64_t( 0x79cc ) << 0x20 ) \
                                                        | (uint64_t( 0xf5c7 ) << 0x10 ) \
                                                        | (uint64_t( 0x3480 )         ) \
                                                        )

#define BEOWULF_APR_PERCENT_SHIFT_PER_ROUND             83

// We have different constants for hourly rewards
// i.e. hex(int(math.expm1( math.log1p( 1 ) / HOURS_PER_YEAR ) * 2**BEOWULF_APR_PERCENT_SHIFT_PER_HOUR / 100000 + 0.5))
#define BEOWULF_APR_PERCENT_MULTIPLY_PER_HOUR           ( (uint64_t( 0x6cc1 ) << 0x20) \
                                                        | (uint64_t( 0x39a1 ) << 0x10) \
                                                        | (uint64_t( 0x5cbd )        ) \
                                                        )

// chosen to be the maximal value such that BEOWULF_APR_PERCENT_MULTIPLY_PER_HOUR * 2**64 * 100000 < 2**128
#define BEOWULF_APR_PERCENT_SHIFT_PER_HOUR              77

// These constants add up to GRAPHENE_100_PERCENT.  Each GRAPHENE_1_PERCENT is equivalent to 1% per year APY
// *including the corresponding 9x vesting rewards*
//#define BEOWULF_CURATE_APR_PERCENT              3875
//#define BEOWULF_CONTENT_APR_PERCENT             3875
#define BEOWULF_LIQUIDITY_APR_PERCENT            3000 //750
#define BEOWULF_PRODUCER_APR_PERCENT             4000 //750
#define BEOWULF_POW_APR_PERCENT                  3000 //750

#define BEOWULF_MIN_PAYOUT_SBD                  (asset(20,SBD_SYMBOL))

#define BEOWULF_SBD_STOP_PERCENT_HF14           (5*BEOWULF_1_PERCENT ) // Stop printing SBD at 5% Market Cap
#define BEOWULF_SBD_STOP_PERCENT_HF20           (10*BEOWULF_1_PERCENT ) // Stop printing SBD at 10% Market Cap
#define BEOWULF_SBD_START_PERCENT_HF14          (2*BEOWULF_1_PERCENT) // Start reducing printing of SBD at 2% Market Cap
#define BEOWULF_SBD_START_PERCENT_HF20          (9*BEOWULF_1_PERCENT) // Start reducing printing of SBD at 9% Market Cap

#define BEOWULF_MIN_ACCOUNT_NAME_LENGTH          3
#define BEOWULF_MAX_ACCOUNT_NAME_LENGTH         16

//#define BEOWULF_MIN_PERMLINK_LENGTH             0
//#define BEOWULF_MAX_PERMLINK_LENGTH             256
#define BEOWULF_MAX_WITNESS_URL_LENGTH          2048

#define BEOWULF_MAX_SHARE_SUPPLY                uint64_t(1000000000000000000ll)
#define BEOWULF_MAX_SATOSHIS                    int64_t(4611686018427387903ll)
#define BEOWULF_MAX_SIG_CHECK_DEPTH             2
#define BEOWULF_MAX_SIG_CHECK_ACCOUNTS          125

#define BEOWULF_MIN_TRANSACTION_SIZE_LIMIT      1024
#define BEOWULF_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

//#define BEOWULF_SBD_INTEREST_COMPOUND_INTERVAL_SEC  (60*60*24*30)
#define BEOWULF_MAX_TRANSACTION_SIZE            (1024*64)/16
#define BEOWULF_MIN_BLOCK_SIZE_LIMIT            (BEOWULF_MAX_TRANSACTION_SIZE)
#define BEOWULF_MAX_BLOCK_SIZE                  (BEOWULF_MAX_TRANSACTION_SIZE*BEOWULF_BLOCK_INTERVAL*2000*16)
#define BEOWULF_SOFT_MAX_BLOCK_SIZE             (2*1024*1024)
#define BEOWULF_MIN_BLOCK_SIZE                  115
#define BEOWULF_BLOCKS_PER_HOUR                 (60*60/BEOWULF_BLOCK_INTERVAL)
/**
 * For testing
 * */
#define BEOWULF_BLOCKS_PER_5MINUTES             (60*5/BEOWULF_BLOCK_INTERVAL)
#define BEOWULF_FEED_INTERVAL_BLOCKS            (BEOWULF_BLOCKS_PER_5MINUTES)
#define BEOWULF_FEED_HISTORY_WINDOW_PRE_HF_16   (24*7) /// 7 days * 24 hours per day
#define BEOWULF_FEED_HISTORY_WINDOW             (12*7) // 3.5 days
#define BEOWULF_MAX_FEED_AGE_SECONDS            (60*60*24*7) // 7 days
#define BEOWULF_MIN_FEEDS                       (BEOWULF_MAX_WITNESSES/3) /// protects the network from conversions before price has been established
#define BEOWULF_CONVERSION_DELAY_PRE_HF_16      (fc::days(7))
#define BEOWULF_CONVERSION_DELAY                (fc::hours(BEOWULF_FEED_HISTORY_WINDOW)) //3.5 day conversion

#define BEOWULF_MIN_UNDO_HISTORY                10
#define BEOWULF_MAX_UNDO_HISTORY                10000

#define BEOWULF_MIN_TRANSACTION_EXPIRATION_LIMIT (BEOWULF_BLOCK_INTERVAL * 5) // 5 transactions per block
#define BEOWULF_BLOCKCHAIN_PRECISION            uint64_t( 100000 )

#define BEOWULF_BLOCKCHAIN_PRECISION_DIGITS     5
#define BEOWULF_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
#define BEOWULF_MIN_WITNESS_FUND                int64_t(300000000000ll)//3000000000
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define BEOWULF_MAX_AUTHORITY_MEMBERSHIP        40
#define BEOWULF_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define BEOWULF_MAX_URL_LENGTH                  127

#define BEOWULF_IRREVERSIBLE_THRESHOLD          (75 * BEOWULF_1_PERCENT)

#define BEOWULF_VIRTUAL_SCHEDULE_LAP_LENGTH  ( fc::uint128(uint64_t(-1)) )
#define BEOWULF_VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

#define BEOWULF_INITIAL_VOTE_POWER_RATE (40)
#define BEOWULF_REDUCED_VOTE_POWER_RATE (10)

//#define BEOWULF_MAX_LIMIT_ORDER_EXPIRATION     (60*60*24*28) // 28 days
//#define BEOWULF_DELEGATION_RETURN_PERIOD_HF0   (BEOWULF_CASHOUT_WINDOW_SECONDS)
//#define BEOWULF_DELEGATION_RETURN_PERIOD_HF20  (BEOWULF_VOTING_MANA_REGENERATION_SECONDS)

#define BEOWULF_RD_MIN_DECAY_BITS               6
#define BEOWULF_RD_MAX_DECAY_BITS              32
#define BEOWULF_RD_DECAY_DENOM_SHIFT           36
#define BEOWULF_RD_MAX_POOL_BITS               64
#define BEOWULF_RD_MAX_BUDGET_1                ((uint64_t(1) << (BEOWULF_RD_MAX_POOL_BITS + BEOWULF_RD_MIN_DECAY_BITS - BEOWULF_RD_DECAY_DENOM_SHIFT))-1)
#define BEOWULF_RD_MAX_BUDGET_2                ((uint64_t(1) << (64-BEOWULF_RD_DECAY_DENOM_SHIFT))-1)
#define BEOWULF_RD_MAX_BUDGET_3                (uint64_t( std::numeric_limits<int32_t>::max() ))
#define BEOWULF_RD_MAX_BUDGET                  (int32_t( std::min( { BEOWULF_RD_MAX_BUDGET_1, BEOWULF_RD_MAX_BUDGET_2, BEOWULF_RD_MAX_BUDGET_3 } )) )
#define BEOWULF_RD_MIN_DECAY                   (uint32_t(1) << BEOWULF_RD_MIN_DECAY_BITS)
#define BEOWULF_RD_MIN_BUDGET                  1
#define BEOWULF_RD_MAX_DECAY                   (uint32_t(0xFFFFFFFF))

//#define BEOWULF_ACCOUNT_SUBSIDY_PRECISION      (BEOWULF_100_PERCENT)

// We want the global subsidy to run out first in normal (Poisson)
// conditions, so we boost the per-witness subsidy a little.
//#define BEOWULF_WITNESS_SUBSIDY_BUDGET_PERCENT (125 * BEOWULF_1_PERCENT)

// Since witness decay only procs once per round, multiplying the decay
// constant by the number of witnesses means the per-witness pools have
// the same effective decay rate in real-time terms.
//#define BEOWULF_WITNESS_SUBSIDY_DECAY_PERCENT  (BEOWULF_MAX_WITNESSES * BEOWULF_100_PERCENT)

// 347321 corresponds to a 5-day halflife
//#define BEOWULF_DEFAULT_ACCOUNT_SUBSIDY_DECAY  (347321)
// Default rate is 0.5 accounts per block
//#define BEOWULF_DEFAULT_ACCOUNT_SUBSIDY_BUDGET (797)
//#define BEOWULF_DECAY_BACKSTOP_PERCENT         (90 * BEOWULF_1_PERCENT)

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define BEOWULF_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define BEOWULF_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define BEOWULF_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define BEOWULF_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define BEOWULF_ROOT_POST_PARENT                (account_name_type())
///@}

//#ifdef BEOWULF_ENABLE_SMT

//#define SMT_MAX_VOTABLE_ASSETS 2
//#define SMT_VESTING_WITHDRAW_INTERVAL_SECONDS   (60*60*24*7) /// 1 week per interval
//#define SMT_UPVOTE_LOCKOUT                      (60*60*12)   /// 12 hours
//#define SMT_EMISSION_MIN_INTERVAL_SECONDS       (60*60*6)    /// 6 hours
//#define SMT_EMIT_INDEFINITELY                   (std::numeric_limits<uint32_t>::max())
//#define SMT_MAX_NOMINAL_VOTES_PER_DAY           (1000)
//#define SMT_MAX_VOTES_PER_REGENERATION          ((SMT_MAX_NOMINAL_VOTES_PER_DAY * SMT_VESTING_WITHDRAW_INTERVAL_SECONDS) / 86400)
//#define SMT_DEFAULT_VOTES_PER_REGEN_PERIOD      (50)
//#define SMT_DEFAULT_PERCENT_CURATION_REWARDS    (25 * BEOWULF_1_PERCENT)
#define SMT_TOKEN_CREATION_FEE                  int64_t(2000000)

//#endif /// BEOWULF_ENABLE_SMT

#define ENABLE_CONVERSION_TO_SBD                 false
#define ENABLE_CONVERSION_FROM_SBD               false
#define BEOWULF_1_BEOWULF                            100000 //due to Precision = 5
#define BEOWULF_1_VESTS                            1000000 //due to Precision = 6