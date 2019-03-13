
#include <beowulf/plugins/rc/resource_user.hpp>

#include <beowulf/protocol/transaction.hpp>

namespace beowulf { namespace plugins { namespace rc {

using namespace beowulf::protocol;

account_name_type get_resource_user( const signed_transaction& tx )
{
   flat_set< account_name_type > req_active;
   flat_set< account_name_type > req_owner;
   //flat_set< account_name_type > req_posting;
   vector< authority > other;

   for( const operation& op : tx.operations )
   {
      operation_get_required_authorities( op, req_active, req_owner, other );
      for( const account_name_type& account : req_active )
         return account;
      for( const account_name_type& account : req_owner )
         return account;
//      for( const account_name_type& account : req_posting )
//         return account;
   }
   return account_name_type();
}

} } } // beowulf::plugins::rc
