#include <steem/protocol/authority.hpp>

#include <steem/chain/util/impacted.hpp>

#include <fc/utility.hpp>
#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>

#include <fc/io/json.hpp>
#include <fc/reflect/reflect.hpp>
#include <fc/variant.hpp>

#include <steem/utilities/key_conversion.hpp>

#include <steem/protocol/steem_operations.hpp>
#include <steem/protocol/transaction.hpp>
#include <steem/protocol/types.hpp>
#include <steem/protocol/asset.hpp>

#include <steem/chain/database.hpp>
#include <chainbase/chainbase.hpp>

#define CHAIN_ID_PARAM "--chain-id"
using namespace fc;
using namespace steem::protocol;
using namespace std;
using namespace steem::chain;
using namespace chainbase;

struct tx_signing_request
{
   steem::protocol::transaction     tx;
   std::string                      wif;
};

struct tx_signing_result
{
   steem::protocol::transaction     tx;
   fc::sha256                       digest;
   fc::sha256                       sig_digest;
   steem::protocol::public_key_type key;
   steem::protocol::signature_type  sig;
};

struct error_result
{
   std::string error;
};

FC_REFLECT( tx_signing_request, (tx)(wif) )
FC_REFLECT( tx_signing_result, (digest)(sig_digest)(key)(sig) )
FC_REFLECT( error_result, (error) )

int main(int argc, char** argv, char** envp)
{
   fc::sha256 chainId;

   chainId = STEEM_CHAIN_ID;

   const size_t chainIdLen = strlen(CHAIN_ID_PARAM);

   if(argc > 1 && !strncmp(argv[1], CHAIN_ID_PARAM, chainIdLen))
   {
      const char* strChainId = argv[1] + chainIdLen;
      if(*strChainId == '=')
      {
         ++strChainId;
         if(*strChainId == '\0')
         {
            if(argc == 2)
            {
               /// --chain-id=
               std::cerr << "Missing parameter for `--chain-id' option. Option ignored, default chain-id used."
                  << std::endl;
               std::cerr << "Usage: sign_transaction [--chain-id=<hex-chain-id>]" << std::endl;
            }
            else
            {
               /// --chain-id= XXXXX
               strChainId = argv[2]; /// ChainId passed as another parameter
            }
         }
      }
      else
      if(argc > 2)
      {
         /// ChainId passed as another parameter
         strChainId = argv[2];
      }
      else
      {
         std::cerr << "Missing parameter for `--chain-id' option. Option ignored, default chain-id used."
            << std::endl;
         std::cerr << "Usage: sign_transaction [--chain-id=<hex-chain-id>]" << std::endl;
      }

      if(*strChainId != '\0')
      {
         try
         {
            fc::sha256 parsedId(strChainId);
            chainId = parsedId;
            std::cerr << "Using explicit chain-id: `" << strChainId << "'" << std::endl;
         }
         catch(const fc::exception& e)
         {
            std::cerr << "Specified explicit chain-id : `" << strChainId << "' is invalid. Option ignored, default chain-id used." << std::endl;
            auto error = e.to_detail_string();
            std::cerr << error << std::endl;
         }
      }
   }

   // hash key pairs on stdin
   std::string hash, wif;
   while( std::cin )
   {
      std::string line;
      std::getline( std::cin, line );
      boost::trim(line);
      if( line == "" )
         continue;

      try
      {
         fc::variant v = fc::json::from_string( line, fc::json::strict_parser );
         tx_signing_request sreq;
         fc::from_variant( v, sreq );

         tx_signing_result sres;
         sres.tx = sreq.tx;
         sres.digest = sreq.tx.digest();
         sres.sig_digest = sreq.tx.sig_digest(chainId);

         auto priv_key = steem::utilities::wif_to_key( sreq.wif );

         if(priv_key)
         {
            sres.sig = priv_key->sign_compact( sres.sig_digest );
            sres.key = steem::protocol::public_key_type( priv_key->get_public_key() );
            std::string sres_str = fc::json::to_string( sres );
            std::cout << "{\"result\":" << sres_str << "}" << std::endl;
         }
         else
         {
            if(sreq.wif.empty())
               std::cerr << "Missing Wallet Import Format in the input JSON structure" << std::endl;
            else
               std::cerr << "Passed JSON points to invalid data according to Wallet Import Format specification: `" << sreq.wif << "'" << std::endl;
         }
      }
      catch( const fc::exception& e )
      {
         error_result eresult;
         eresult.error = e.to_detail_string();
         std::cout << fc::json::to_string( eresult ) << std::endl;
      }
   }
   return 0;
}

//struct get_impacted_fee {
//    asset &_impacted;
//
//    get_impacted_fee(asset &impact) : _impacted(impact) {}
//
//    typedef void result_type;
//
//    template<typename T>
//    void operator()(const T &op) {
//        //op.get_required_posting_authorities(_impacted);
//        //op.get_required_active_authorities(_impacted);
//        //op.get_required_owner_authorities(_impacted);
//    }
//
//    // ops
//    void operator()(const account_create_operation &op) {
//        _impacted = op.fee;
//    }
//
//    void operator()(const account_create_with_delegation_operation &op) {
//        _impacted = op.fee;
//    }
//
////            void operator()(const comment_operation &op) {
////            }
////
////            void operator()(const vote_operation &op) {
////            }
//
//    void operator()(const transfer_operation &op) {
//        _impacted = op.fee;
//    }
//
////            void operator()(const escrow_transfer_operation &op) {
////               _impacted = op.fee;
////            }
////
////            void operator()(const escrow_approve_operation &op) {
////            }
////
////            void operator()(const escrow_dispute_operation &op) {
////            }
////
////            void operator()(const escrow_release_operation &op) {
////            }
//
//    void operator()(const transfer_to_vesting_operation &op) {
//    }
//
//    void operator()(const set_withdraw_vesting_route_operation &op) {
//    }
//
//    void operator()(const account_witness_vote_operation &op) {
//    }
//
//    void operator()(const account_witness_proxy_operation &op) {
//    }
//
//    void operator()(const feed_publish_operation &op) {
//    }
//
//    void operator()(const pow_operation &op) {
//    }
//
//    void operator()(const pow2_operation &op) {
//    }
//
//    void operator()(const request_account_recovery_operation &op) {
//    }
//
//    void operator()(const recover_account_operation &op) {
//    }
//
//    void operator()(const change_recovery_account_operation &op) {
//    }
//
//    void operator()(const transfer_to_savings_operation &op) {
//    }
//
//    void operator()(const transfer_from_savings_operation &op) {
//    }
//
//    void operator()(const delegate_vesting_shares_operation &op) {
//    }
//
//    void operator()(const witness_set_properties_operation &op) {
//    }
//
//    void operator()(const create_claimed_account_operation &op) {
//    }
//
//
//    // vops
//
////   void operator()( const author_reward_operation& op )
////   {
////      _impacted.insert( op.author );
////   }
////
////   void operator()( const curation_reward_operation& op )
////   {
////      _impacted.insert( op.curator );
////   }
//
//    void operator()(const liquidity_reward_operation &op) {
//    }
//
//    void operator()(const interest_operation &op) {
//    }
//
//    void operator()(const fill_convert_request_operation &op) {
//    }
//
//    void operator()(const fill_vesting_withdraw_operation &op) {
//    }
//
//    void operator()(const shutdown_witness_operation &op) {
//    }
//
//    void operator()(const fill_order_operation &op) {
//    }
//
//    void operator()(const fill_transfer_from_savings_operation &op) {
//    }
//
//    void operator()(const return_vesting_delegation_operation &op) {
//    }
//
////   void operator()( const comment_benefactor_reward_operation& op )
////   {
////      _impacted.insert( op.benefactor );
////      _impacted.insert( op.author );
////   }
//
//    void operator()(const producer_reward_operation &op) {
//    }
//
//    void operator()(const hardfork_operation &op) {
//    }
//
//    //void operator()( const operation& op ){}
//};
//
//void operation_get_impacted_fee(const operation &op, asset &result) {
//    get_impacted_fee vtor = get_impacted_fee(result);
//    op.visit(vtor);
//}
//
//int main(int argc, char** argv, char** envp){
//   std::cout << "Start new code to test";
//   steem::protocol::transfer_operation op;
//   op.from = "alice";
//   op.to = "bob";
//   op.amount = steem::protocol::asset(100, STEEM_SYMBOL);
//   op.fee = steem::protocol::asset(1, SBD_SYMBOL);
//
//    steem::protocol::transfer_operation op1;
//    op1.from = "alice";
//    op1.to = "bob";
//    op1.amount = steem::protocol::asset(100, STEEM_SYMBOL);
//    op1.fee = steem::protocol::asset(2, SBD_SYMBOL);
//
//    steem::protocol::transfer_operation op2;
//    op2.from = "alice";
//    op2.to = "bob";
//    op2.amount = steem::protocol::asset(100, STEEM_SYMBOL);
//    //op1.fee = steem::protocol::asset(2, STEEM_SYMBOL);
//
//    steem::protocol::transfer_to_vesting_operation op3;
//    op3.from = "alice";
//    op3.to = "bob";
//    op3.amount= steem::protocol::asset(100, STEEM_SYMBOL);
//
//    steem::protocol::transfer_operation op4;
//    op4.from = "alice";
//    op4.to = "bob";
//    op4.amount= steem::protocol::asset(100, STEEM_SYMBOL);
//    op4.fee = steem::protocol::asset(2, VESTS_SYMBOL);
//
//   steem::protocol::transaction trx;
//
//   //trx.operations.push_back( op );
//    //trx.operations.push_back( op1 );
//    //trx.operations.push_back( op2 );
//    //trx.operations.push_back( op3 );
//    //trx.operations.push_back( op4 );
//    //trx.validate();
//    asset totalFeeInSBD = asset(0, SBD_SYMBOL);
//    asset totalFeeInSteem = asset(0, STEEM_SYMBOL);
//
//        for (const operation &op : trx.operations) {
//            asset fee;
//            operation_get_impacted_fee(op, fee);
//            if(fee.symbol == SBD_SYMBOL){
//                totalFeeInSBD += fee;
//            }else if(fee.symbol == STEEM_SYMBOL) {
//                totalFeeInSteem += fee;
//            }
//        }
//    if(totalFeeInSBD > asset(0,SBD_SYMBOL)){
//        std::cout<<"SBD have value";
//    }
//    if(totalFeeInSteem > asset(0,STEEM_SYMBOL)){
//        std::cout<<"Steem have value";
//    }
////    steem::plugins::rc::get_resource_user_visitor vtor;
////
////    for( const steem::protocol::operation& op : trx.operations )
////    {
////        account_name_type resource_user = op.visit( vtor );
////        if( resource_user != account_name_type() )
////            return resource_user;
////    }
//
////    for( const auto& o : trx.operations )
////    {
////        legacy_operation op;
////        o.visit( legacy_operation_conversion_visitor( op ) );
////        operations.push_back( op );
////    }
//   //trx.validate();
////    auto packed = fc::raw::pack_to_vector( trx );
////    steem::protocol::signed_transaction unpacked = fc::raw::unpack_from_vector<steem::protocol::signed_transaction>(packed);
////    unpacked.validate();
////    if(trx.digest() == unpacked.digest()){
////        return 0;
////    }
//   return 1;
//}

