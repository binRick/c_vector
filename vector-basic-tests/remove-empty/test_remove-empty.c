#include "vector-test-utils/vector-test-utils.h"
#include "vector.h"

void test_impl(){
  struct Vector *vector = vector_new_with_options(2, true);

  assert_true(vector_remove(vector, 0) == NULL);

  assert_true(vector_is_empty(vector));
  assert_num_equal(vector_capacity(vector), 2);

  vector_release(vector);
}

int main(){
  test_run(test_impl);
}
