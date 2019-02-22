#pragma once

#include <vector>

namespace steem{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "seed-east.steemit.com:2001",          // steemit
   "seed-central.steemit.com:2001",       // steemit
   "seed-west.steemit.com:2001"          // steemit
};
#endif

} } } // steem::plugins::p2p
