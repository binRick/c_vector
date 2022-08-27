////////////////////////////////////////////
#include "c_greatest/greatest/greatest.h"
#include "vector-filter-test/vector-filter-test.h"
////////////////////////////////////////////

TEST t_vector_filter_size_test(){
  size_t qty0 = vector_filter_size(init_club_vector(), ^ bool (__attribute__((unused)) size_t i, void *I){
    return((((struct club_t *)I)->points > 50) ? true : false);
  });
  size_t qty1 = vector_filter_size(init_club_vector(), ^ bool (__attribute__((unused)) size_t i, void *I){
    return((((struct club_t *)I)->points > 5000) ? true : false);
  });
  size_t qty2 = vector_filter_size(init_club_vector(), ^ bool (__attribute__((unused)) size_t i, void *I){
    return((((struct club_t *)I)->points > 0) ? true : false);
  });

  ASSERT_EQ(qty0, 3);
  ASSERT_EQ(qty1, 0);
  ASSERT_EQ(qty2, vector_size(init_club_vector()));
  PASS();
}

TEST t_vector_filter_mut_test(){
  struct Vector *Clubs1 = init_club_vector();
  struct Vector *Clubs2 = vector_filter_mut(Clubs1, ^ bool (__attribute__((unused)) size_t i, void *I){
    return((((struct club_t *)I)->points > 50) ? true : false);
  });

  print_titled_club("Clubs1", Clubs1);
  print_titled_club("Clubs2", Clubs2);
  {
    ASSERT_LTE(vector_size(Clubs1), vector_size(init_club_vector()));
    ASSERT_EQ(vector_size(Clubs1), vector_size(Clubs2));
  }
  PASS();
}

TEST t_vector_filter_new_test(){
  struct Vector *Clubs         = init_club_vector();
  struct Vector *FilteredClubs = vector_filter_new(Clubs, ^ bool (__attribute__((unused)) size_t i, void *I){
    return((((struct club_t *)I)->points > 50) ? true : false);
  });

  print_titled_club("Clubs", Clubs);
  print_titled_club("Filtered Clubs", FilteredClubs);
  {
    ASSERT_LTE(vector_size(FilteredClubs), vector_size(init_club_vector()));
    ASSERT_EQ(vector_size(Clubs), vector_size(init_club_vector()));
    ASSERT_LTE(vector_size(FilteredClubs), vector_size(Clubs));
  }
  PASS();
}

SUITE(s_vector_filter_test) {
  RUN_TEST(t_vector_filter_new_test);
  RUN_TEST(t_vector_filter_mut_test);
  RUN_TEST(t_vector_filter_size_test);
}

GREATEST_MAIN_DEFS();

int main(const int argc, const char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(s_vector_filter_test);
  GREATEST_MAIN_END();
}
