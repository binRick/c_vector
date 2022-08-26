#include "vector-test-utils/vector-test-utils.h"
#include "vector.h"

void test_impl(){
  struct Vector *vector = vector_new();

  assert_true(vector_is_empty(vector));
  assert_num_equal(vector_capacity(vector), 20);

  assert_true(vector_shrink(vector));

  assert_true(vector_is_empty(vector));
  assert_num_equal(vector_capacity(vector), 0);

  vector_release(vector);
}

int main(){
  test_run(test_impl);
}
