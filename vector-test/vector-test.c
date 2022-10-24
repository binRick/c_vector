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

#define LEN    10

TEST t_vector_from_array(){
  char **a;

  a    = calloc(1, 1024);
  a[0] = "xx1xx";
  a[1] = "yy";
  a[2] = "zz";
  struct Vector *v = NULL;

  v = vector_from_array((void **)a, 3 * sizeof(char *), 3);
  fprintf(stdout, "size:%lu\n", vector_size(v));
  fprintf(stdout, "i0:%s\n", (char *)vector_get(v, 0));
  fprintf(stdout, "i1:%s\n", (char *)vector_get(v, 1));
  fprintf(stdout, "ilast:%s\n", (char *)(vector_get(v, vector_size(v) - 1)));
#undef LEN
  PASS();
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
  RUN_TEST(t_vector_from_array);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(s_vector_sort);
  GREATEST_MAIN_END();
}
