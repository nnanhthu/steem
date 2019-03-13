#pragma once

#include <vector>

namespace beowulf{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "seed-east.beowulfit.com:2001",          // beowulfit
   "seed-central.beowulfit.com:2001",       // beowulfit
   "seed-west.beowulfit.com:2001"          // beowulfit
};
#endif

} } } // beowulf::plugins::p2p
