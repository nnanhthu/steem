#pragma once

namespace beowulf { namespace protocol {

// TODO:  Rename these curves to match naming in manual.md
enum curve_id
{
   quadratic,
   quadratic_curation,
   linear,
   square_root
};

} } // beowulf::utilities


FC_REFLECT_ENUM(
   beowulf::protocol::curve_id,
   (quadratic)
   (quadratic_curation)
   (linear)
   (square_root)
)
