////////////////////////////////////////////
#include <stdio.h>
////////////////////////////////////////////
#include "vector-for-each-test/vector-for-each-test.h"
////////////////////////////////////////////
#include "c_greatest/greatest/greatest.h"
#include "c_vector/vector/vector.h"

int print_item(size_t i, void *I){
  printf("Handling %lu: %s\n", i, (char *)I);
  return(((i > 3) ? -1 : 0));
}
struct Vector *init_vector1(){
  struct Vector *v = vector_new();
  size_t        i[10];

  i[0] = 12345;
  i[1] = 222222;
  i[2] = 3333333;
  vector_push(v, (void *)i[0]);
  vector_push(v, (void *)i[1]);
  vector_push(v, (void *)i[2]);
  return(v);
}

struct Vector *init_vector(){
  struct Vector *v = vector_new();
  char          *i[10];

  i[0] = "aaaaaaaaaaaaa";
  i[1] = "bbbbbbbbbbbbb";
  i[2] = "ccccccccccccc";
  i[3] = "dddddddddddd";
  i[4] = "eeeeeeeeEEEEE";
  i[5] = "ffffffffffff";
  vector_push(v, (void *)i[0]);
  vector_push(v, (void *)i[1]);
  vector_push(v, (void *)i[2]);
  vector_push(v, (void *)i[3]);
  vector_push(v, (void *)i[4]);
  vector_push(v, (void *)i[5]);
  return(v);
}

TEST t_vector_for_each_block_autocast_test_ints(){
  struct Vector *v        = init_vector1();
  int           outer_var = 100;

  VECTOR_FOREACH_AUTOCAST(v, size_t, ^ int (size_t i, size_t I){
    int inner_var = outer_var + i;
    printf("[AUTOCAST SIZE_T BLOCK] Handling %lu: %lu :: outer_val:%d:inner_var:%d\n", i, I, outer_var, inner_var);
    return(((i > 2) ? -1 : 0));
  });
  PASS();
}

TEST t_vector_for_each_block_autocast_test(){
  struct Vector *v        = init_vector();
  int           outer_var = 100;

  VECTOR_FOREACH_AUTOCAST(v, char *, ^ int (size_t i, char *I){
    int inner_var = outer_var + i;
    printf("[AUTOCAST BLOCK] Handling %lu: %s :: outer_val:%d:inner_var:%d\n", i, I, outer_var, inner_var);
    return(((i > 2) ? -1 : 0));
  });

  PASS();
}

TEST t_vector_for_each_block_test(){
  struct Vector *v        = init_vector();
  int           outer_var = 100;

  vector_foreach_block(v, ^ int (size_t i, void *I){
    int inner_var = outer_var + i;
    printf("[BLOCK] Handling %lu: %s :: outer_val:%d:inner_var:%d\n", i, (char *)I, outer_var, inner_var);
    return(((i > 2) ? -1 : 0));
  });

  PASS();
}

TEST t_vector_for_each_test(){
  struct Vector *v = init_vector();

  printf("%lu\n", vector_size(v));
  vector_foreach(v, print_item);
  PASS();
}

SUITE(s_vector_for_each_test) {
  RUN_TEST(t_vector_for_each_test);
  RUN_TEST(t_vector_for_each_block_test);
  RUN_TEST(t_vector_for_each_block_autocast_test);
  RUN_TEST(t_vector_for_each_block_autocast_test_ints);
}

GREATEST_MAIN_DEFS();

int main(const int argc, const char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(s_vector_for_each_test);
  GREATEST_MAIN_END();
}
