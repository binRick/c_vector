#include "vector-test-utils/vector-test-utils.h"
#include "vector.h"

void test_impl(){
  struct Vector *vector = vector_new();

  assert_true(vector_is_empty(vector));

  void *item = vector_pop(vector);

  assert_true(item == NULL);

  assert_true(vector_is_empty(vector));

  vector_release(vector);
}

int main(){
  test_run(test_impl);
}
