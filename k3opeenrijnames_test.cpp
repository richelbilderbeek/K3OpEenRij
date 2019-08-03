#include "k3opeenrijnames.h"

#include <fstream>

#include <boost/test/unit_test.hpp>

using namespace ribi::koer;

BOOST_AUTO_TEST_CASE(koer_get_next)
{
  const BlackHairedGirl b = BlackHairedGirl::kristel;
  const BlackHairedGirl c = GetNext(b);
  BOOST_CHECK_NE(b, c);
}



