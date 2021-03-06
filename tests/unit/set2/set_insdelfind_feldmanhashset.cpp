//$$CDS-header$$

#include "set2/set_insdelfind.h"
#include "set2/set_type_feldman_hashset.h"

#undef TEST_CASE
#define TEST_CASE(TAG, X)  void Set_InsDelFind::X() { run_test<typename set_type< TAG, key_type, value_type>::X>(); }
#include "set2/set_defs.h"

namespace set2 {
    CDSUNIT_DECLARE_FeldmanHashSet
} // namespace set2
