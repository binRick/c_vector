#include "test.h"
#include "vector.h"

void test_impl(){
  struct Vector *vector = vector_new_with_options(2, true);

  vector_push(vector, "test");
  vector_push(vector, "test");
  vector_push(vector, "test");

  assert_true(!vector_is_empty(vector));
  assert_num_equal(vector_capacity(vector), 4);

  assert_true(vector_clear(vector));

  assert_true(vector_is_empty(vector));
  assert_num_equal(vector_capacity(vector), 4);

  vector_release(vector);
}

int main(){
  test_run(test_impl);
}
