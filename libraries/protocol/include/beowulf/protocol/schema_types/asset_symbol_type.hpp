
#pragma once

#include <beowulf/schema/abstract_schema.hpp>
#include <beowulf/schema/schema_impl.hpp>

#include <beowulf/protocol/asset_symbol.hpp>

namespace beowulf { namespace schema { namespace detail {

//////////////////////////////////////////////
// asset_symbol_type                        //
//////////////////////////////////////////////

struct schema_asset_symbol_type_impl
   : public abstract_schema
{
   BEOWULF_SCHEMA_CLASS_BODY( schema_asset_symbol_type_impl )
};

}

template<>
struct schema_reflect< beowulf::protocol::asset_symbol_type >
{
   typedef detail::schema_asset_symbol_type_impl           schema_impl_type;
};

} }
