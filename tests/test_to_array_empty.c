#include "test.h"
#include "vector.h"
#include <stdlib.h>

void test_impl(){
  struct Vector *vector = vector_new();

  assert_true(vector_is_empty(vector));

  void **array = vector_to_array(vector);

  assert_true(array[0] == NULL);

  vector_release(vector);
  free(array);
}

int main(){
  test_run(test_impl);
}
