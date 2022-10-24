#include "c_greatest/greatest/greatest.h"
#include "vector/vector.h"
#include "vector-sort-test/vector-sort-test.h"
#include "vector-test-utils/vector-test-utils.h"

int club_sort_function(const void *I0, const void *I1){
  struct club_t *C0 = (struct club_t *)I0;
  struct club_t *C1 = (struct club_t *)I1;
  int           ret = (C0->points > C1->points)
              ? 1
              : (C0->points < C1->points)
                ? -1
                : 0;

  return(ret);
}

TEST t_vector_sort_test(){
  struct Vector *clubs = init_club_vector();

  vector_foreach(clubs, print_club);

  struct club_t *sorted_clubs = calloc((vector_size(clubs) + 1), sizeof(struct club_t));

  for (size_t i = 0; i < vector_size(clubs); i++) {
    sorted_clubs[i] = *((struct club_t *)vector_get(clubs, i));
  }

  qsort(sorted_clubs, vector_size(clubs), sizeof(struct club_t), club_sort_function);
  for (size_t i = 0; i < vector_size(clubs); i++) {
    printf("Club #%lu/%lu: %s : %d\n",
           i + 1, vector_size(clubs),
           ((struct club_t *)(&sorted_clubs[i]))->name,
           ((struct club_t *)(&sorted_clubs[i]))->points
           );
  }

  PASS();
}

SUITE(s_vector_sort_test) {
  RUN_TEST(t_vector_sort_test);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(s_vector_sort_test);
  GREATEST_MAIN_END();
}
