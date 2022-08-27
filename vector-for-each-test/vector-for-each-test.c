#include "c_greatest/greatest/greatest.h"
#include "c_vector/vector-for-each-test/vector-for-each-test.h"
////////////////////////////////////////////

TEST t_vector_for_each_autocast_tests(){
  {
    int outer_var = 100;
    vector_foreach_cast(init_vector1(), size_t, (size_t i, size_t I){
      int inner_var = outer_var + i;
      printf("[AUTOCAST size_t] Handling %lu: %lu :: outer_val:%d:inner_var:%d\n", i, I, outer_var, inner_var);
      return(((i > 2) ? -1 : 0));
    });
  }
  {
    vector_foreach_cast(init_club_vector(), struct club_t *, (size_t i, struct club_t *club){
      printf("[AUTOCAST club_t*] Club #%lu: %s:%d\n", i, club->name, club->points);
      return(((i > 2) ? -1 : 0));
    });
  }

  PASS();
}

TEST t_vector_for_each_block_test(){
  int outer_var = 100;

  vector_foreach_block(init_vector(), ^ int (size_t i, void *I){
    int inner_var = outer_var + i;
    printf("[BLOCK] Handling %lu: %s :: outer_val:%d:inner_var:%d\n", i, (char *)I, outer_var, inner_var);
    return(((i > 2) ? -1 : 0));
  });

  vector_foreach_block(init_club_vector(), ^ int (size_t i, void *I){
    printf("[BLOCK] Club #%lu: %s:%d\n",
           i,
           ((struct club_t *)I)->name,
           ((struct club_t *)I)->points
           );
    return(((i > 2) ? -1 : 0));
  });

  PASS();
}

TEST t_vector_for_each_test(){
  vector_foreach(init_vector(), print_item);
  vector_foreach(init_club_vector(), print_club);
  PASS();
}

SUITE(s_vector_for_each_test) {
  RUN_TEST(t_vector_for_each_test);
  RUN_TEST(t_vector_for_each_block_test);
  RUN_TEST(t_vector_for_each_autocast_tests);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(s_vector_for_each_test);
  GREATEST_MAIN_END();
}
