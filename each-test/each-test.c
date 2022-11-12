
#include "c_greatest/greatest/greatest.h"
#include "each-test/each-test.h"
#include "vector/vector.h"
static struct Vector *t_init_vector(void);
static struct Vector *t_init_vector(void){
  struct Vector *v = vector_new();
  vector_push(v,(void*)(size_t)0);
  vector_push(v,(void*)(size_t)2);
  vector_push(v,(void*)(size_t)4);
  vector_push(v,(void*)(size_t)6);
  return(v);
}

TEST t_each_index_item_size_t(){
  vector_each_index_item(t_init_vector(),INDEX,size_t,ITEM,{
      fprintf(stdout, "Item #%lu: %lu\n", INDEX, ITEM);
      ASSERT_EQ(ITEM,INDEX*2);
  });
  PASS();
}

TEST t_each_item_size_t(){
  vector_each_item(t_init_vector(),size_t,I,{
      fprintf(stdout, "Item #%lu: %lu\n", i, I);
      ASSERT_EQ(I,i*2);
  });
  PASS();
}

TEST t_each_size_t(){
  vector_each(t_init_vector(),size_t,{
      fprintf(stdout, "Item #%lu: %lu\n", i, item);
      ASSERT_EQ(item,i*2);
  });
  PASS();
}

SUITE(s_each_test) {
  RUN_TEST(t_each_size_t);
  RUN_TEST(t_each_item_size_t);
  RUN_TEST(t_each_index_item_size_t);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(s_each_test);
  GREATEST_MAIN_END();
}
