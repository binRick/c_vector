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
#define PRINT_VECTOR(V)                                 \
  for (size_t i = 0; i < vector_size(V); i++) {         \
    printf("#%lu> %lu\n", i, (size_t)vector_get(V, i)); \
  }

TEST t_vector_sort(){
  struct Vector *v    = vector_new();
  size_t        i[10] = { 123456, 111, 22, 4848, 93333, 131239 };

  vector_push(v, (void *)i[0]);
  vector_push(v, (void *)i[1]);
  vector_push(v, (void *)i[2]);
  vector_push(v, (void *)i[3]);
  PRINT_VECTOR(v)
  PASS();
}

SUITE(s_vector_sort) {
  RUN_TEST(t_vector_sort);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(s_vector_sort);
  GREATEST_MAIN_END();
}
