#include "vector-test-utils/vector-test-utils.h"
#include "vector.h"

void test_impl(){
  struct Vector *vector = vector_new();

  assert_true(vector_push(vector, "12345"));
  assert_true(vector_push(vector, "abcde"));
  assert_true(vector_push(vector, "ABCDE"));

  assert_true(!vector_is_empty(vector));
  assert_num_equal(vector_size(vector), 3);
  assert_num_equal(vector_capacity(vector), 20);

  assert_string_equal((char *)vector_get(vector, 0), "12345");
  assert_string_equal((char *)vector_get(vector, 1), "abcde");
  assert_string_equal((char *)vector_get(vector, 2), "ABCDE");

  vector_release(vector);
}

int main(){
  test_run(test_impl);
}
