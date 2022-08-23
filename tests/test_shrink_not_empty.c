#include "test.h"
#include "vector.h"

void test_impl(){
  struct Vector *vector = vector_new_with_options(2, true);

  vector_push(vector, "test");
  vector_push(vector, "test");
  vector_push(vector, "test");
  vector_push(vector, "test");
  vector_push(vector, "test");

  assert_num_equal(vector_size(vector), 5);
  assert_num_equal(vector_capacity(vector), 8);

  assert_true(vector_shrink(vector));

  assert_num_equal(vector_size(vector), 5);
  assert_num_equal(vector_capacity(vector), 5);

  vector_release(vector);
}

int main(){
  test_run(test_impl);
}
