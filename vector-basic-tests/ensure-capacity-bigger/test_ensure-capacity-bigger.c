#include "vector-test-utils/vector-test-utils.h"
#include "vector.h"

void test_impl(){
  struct Vector *vector = vector_new();

  vector_push(vector, "test");

  assert_true(!vector_is_empty(vector));
  assert_num_equal(vector_capacity(vector), 20);

  assert_true(vector_ensure_capacity(vector, 100));

  assert_num_equal(vector_size(vector), 1);
  assert_num_equal(vector_capacity(vector), 100);

  vector_release(vector);
}

int main(){
  test_run(test_impl);
}
