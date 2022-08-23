#include "test.h"
#include "vector.h"
#include <stdlib.h>

void test_impl(){
  struct Vector *vector = vector_new_with_options(2, false);

  assert_true(vector_push(vector, "12345"));
  assert_true(vector_push(vector, "abcde"));
  assert_true(!vector_push(vector, "ABCDE"));
  assert_true(!vector_push(vector, "test"));

  assert_true(!vector_is_empty(vector));
  assert_num_equal(vector_size(vector), 2);
  assert_num_equal(vector_capacity(vector), 2);

  void **array = vector_to_array(vector);

  assert_string_equal(array[0], "12345");
  assert_string_equal(array[1], "abcde");

  assert_true(array[2] == NULL);

  vector_release(vector);
  free(array);
}

int main(){
  test_run(test_impl);
}
