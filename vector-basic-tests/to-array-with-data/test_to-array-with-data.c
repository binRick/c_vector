#include "vector-test-utils/vector-test-utils.h"
#include "vector.h"
#include <stdlib.h>

void test_impl(){
  struct Vector *vector = vector_new_with_options(2, true);

  vector_push(vector, "test");
  vector_push(vector, "test");
  vector_push(vector, "test");
  vector_push(vector, "test");
  vector_push(vector, "test");

  assert_num_equal(vector_size(vector), 5);
  assert_num_equal(vector_capacity(vector), 8);

  void **array = vector_to_array(vector);

  for (size_t index = 0; index < vector_size(vector); index++) {
    assert_string_equal(array[index], "test");
  }
  assert_true(array[vector_size(vector)] == NULL);

  vector_release(vector);
  free(array);
}

int main(){
  test_run(test_impl);
}
