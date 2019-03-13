
#pragma once

#include <beowulf/schema/abstract_schema.hpp>
#include <beowulf/schema/schema_impl.hpp>

#include <beowulf/protocol/types.hpp>

namespace beowulf { namespace schema { namespace detail {

//////////////////////////////////////////////
// account_name_type                        //
//////////////////////////////////////////////

struct schema_account_name_type_impl
   : public abstract_schema
{
   BEOWULF_SCHEMA_CLASS_BODY( schema_account_name_type_impl )
};

}

template<>
struct schema_reflect< beowulf::protocol::account_name_type >
{
   typedef detail::schema_account_name_type_impl           schema_impl_type;
};

} }

namespace fc {

template<>
struct get_typename< beowulf::protocol::account_name_type >
{
   static const char* name()
   {
      return "beowulf::protocol::account_name_type";
   }
};

}
