#include "vector-test-utils/vector-test-utils.h"
#include "vector.h"

void test_impl(){
  struct Vector *vector = vector_new_with_options(2, true);

  assert_true(vector_push(vector, "12345"));
  assert_true(vector_push(vector, "abcde"));
  assert_true(vector_push(vector, "ABCDE"));

  assert_true(!vector_is_empty(vector));
  assert_num_equal(vector_size(vector), 3);
  assert_num_equal(vector_capacity(vector), 4);

  void *item = vector_pop(vector);

  assert_string_equal(item, "ABCDE");
  item = vector_pop(vector);
  assert_string_equal(item, "abcde");
  item = vector_pop(vector);
  assert_string_equal(item, "12345");
  item = vector_pop(vector);
  assert_true(item == NULL);

  assert_true(vector_is_empty(vector));
  assert_num_equal(vector_size(vector), 0);
  assert_num_equal(vector_capacity(vector), 4);

  vector_release(vector);
}

int main(){
  test_run(test_impl);
}
