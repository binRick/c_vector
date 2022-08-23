////////////////////////////////////////////

#ifdef DEBUG_MEMORY
#include "debug-memory/debug_memory.h"
#endif
////////////////////////////////////////////
#include "vector-test/vector-test.h"
#include "vector/vector.h"
////////////////////////////////////////////
#include "c_greatest/greatest/greatest.h"

////////////////////////////////////////////
TEST t_vector_test(){
  PASS();
}

SUITE(s_vector_test) {
  RUN_TEST(t_vector_test);
}

GREATEST_MAIN_DEFS();

int main(const int argc, const char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(s_vector_test);
  GREATEST_MAIN_END();
}
