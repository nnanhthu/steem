#pragma once

#include <beowulf/protocol/beowulf_operations.hpp>

#include <beowulf/chain/evaluator.hpp>

namespace beowulf { namespace chain {

using namespace beowulf::protocol;

BEOWULF_DEFINE_EVALUATOR( account_create )
//BEOWULF_DEFINE_EVALUATOR( account_create_with_delegation )
BEOWULF_DEFINE_EVALUATOR( account_update )
BEOWULF_DEFINE_EVALUATOR( transfer )
BEOWULF_DEFINE_EVALUATOR( transfer_to_vesting )
BEOWULF_DEFINE_EVALUATOR( witness_update )
BEOWULF_DEFINE_EVALUATOR( account_witness_vote )
//BEOWULF_DEFINE_EVALUATOR( account_witness_proxy )
BEOWULF_DEFINE_EVALUATOR( withdraw_vesting )
BEOWULF_DEFINE_EVALUATOR( set_withdraw_vesting_route )
//BEOWULF_DEFINE_EVALUATOR( comment )
//BEOWULF_DEFINE_EVALUATOR( comment_options )
//BEOWULF_DEFINE_EVALUATOR( delete_comment )
//BEOWULF_DEFINE_EVALUATOR( vote )
//BEOWULF_DEFINE_EVALUATOR( custom )
//BEOWULF_DEFINE_EVALUATOR( custom_json )
//BEOWULF_DEFINE_EVALUATOR( custom_binary )
//BEOWULF_DEFINE_EVALUATOR( pow )
//BEOWULF_DEFINE_EVALUATOR( pow2 )
BEOWULF_DEFINE_EVALUATOR( feed_publish )
BEOWULF_DEFINE_EVALUATOR( convert )
//BEOWULF_DEFINE_EVALUATOR( limit_order_create )
//BEOWULF_DEFINE_EVALUATOR( limit_order_cancel )
BEOWULF_DEFINE_EVALUATOR( report_over_production )
//BEOWULF_DEFINE_EVALUATOR( limit_order_create2 )
//BEOWULF_DEFINE_EVALUATOR( escrow_transfer )
//BEOWULF_DEFINE_EVALUATOR( escrow_approve )
//BEOWULF_DEFINE_EVALUATOR( escrow_dispute )
//BEOWULF_DEFINE_EVALUATOR( escrow_release )
//BEOWULF_DEFINE_EVALUATOR( claim_account )
//BEOWULF_DEFINE_EVALUATOR( create_claimed_account )
//BEOWULF_DEFINE_EVALUATOR( request_account_recovery )
//BEOWULF_DEFINE_EVALUATOR( recover_account )
//BEOWULF_DEFINE_EVALUATOR( change_recovery_account )
//BEOWULF_DEFINE_EVALUATOR( transfer_to_savings )
//BEOWULF_DEFINE_EVALUATOR( transfer_from_savings )
//BEOWULF_DEFINE_EVALUATOR( cancel_transfer_from_savings )
//BEOWULF_DEFINE_EVALUATOR( decline_voting_rights )
//BEOWULF_DEFINE_EVALUATOR( reset_account )
//BEOWULF_DEFINE_EVALUATOR( set_reset_account )
//BEOWULF_DEFINE_EVALUATOR( claim_reward_balance )
//#ifdef BEOWULF_ENABLE_SMT
//BEOWULF_DEFINE_EVALUATOR( claim_reward_balance2 )
//#endif
//BEOWULF_DEFINE_EVALUATOR( delegate_vesting_shares )
BEOWULF_DEFINE_EVALUATOR( witness_set_properties )
//#ifdef BEOWULF_ENABLE_SMT
BEOWULF_DEFINE_EVALUATOR( smt_setup )
//BEOWULF_DEFINE_EVALUATOR( smt_cap_reveal )
//BEOWULF_DEFINE_EVALUATOR( smt_refund )
//BEOWULF_DEFINE_EVALUATOR( smt_setup_emissions )
//BEOWULF_DEFINE_EVALUATOR( smt_set_setup_parameters )
//BEOWULF_DEFINE_EVALUATOR( smt_set_runtime_parameters )
BEOWULF_DEFINE_EVALUATOR( smt_create )
//#endif
BEOWULF_DEFINE_EVALUATOR( convert_to_sbd )

} } // beowulf::chain
