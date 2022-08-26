#include "vector-test-utils/vector-test-utils.h"
#include "vector.h"

void test_impl(){
  struct Vector *vector = vector_new();

  assert_true(vector_is_empty(vector));

  void *item = vector_get(vector, 0);

  assert_true(item == NULL);

  vector_release(vector);
}

int main(){
  test_run(test_impl);
}
