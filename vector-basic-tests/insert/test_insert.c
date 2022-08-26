#include "vector-test-utils/vector-test-utils.h"
#include "vector.h"
#include <stdlib.h>

void test_impl(){
  struct Vector *vector = vector_new_with_options(2, true);

  assert_true(vector_insert(vector, 1, "12345"));
  assert_true(vector_insert(vector, 1, "abcde"));
  assert_true(vector_insert(vector, 1, "ABCDE"));

  assert_true(!vector_is_empty(vector));
  assert_num_equal(vector_size(vector), 4);
  assert_num_equal(vector_capacity(vector), 4);

  void **array = vector_to_array(vector);

  assert_true(array[0] == NULL);
  assert_string_equal(array[1], "ABCDE");
  assert_string_equal(array[2], "abcde");
  assert_string_equal(array[3], "12345");

  assert_true(array[4] == NULL);

  vector_release(vector);
  free(array);
}

int main(){
  test_run(test_impl);
}
