//$$CDS-header$$

#include "set2/set_insdel_string.h"
#include "set2/set_type_cuckoo.h"

#undef TEST_CASE
#define TEST_CASE(TAG, X)  void Set_InsDel_string::X() { run_test<typename set_type< TAG, key_type, value_type>::X>(); }
#include "set2/set_defs.h"

namespace set2 {
    CDSUNIT_DECLARE_CuckooSet
} // namespace set2
