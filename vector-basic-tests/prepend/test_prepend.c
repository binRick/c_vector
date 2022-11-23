#include "vector-test-utils/vector-test-utils.h"
#include "vector.h"
#include <stdlib.h>

void benchmark_impl(){
  struct Vector *vector = vector_new();


}
void test_impl(){
  struct Vector *vector = vector_new();

  assert_true(vector_prepend(vector, "12345"));
  assert_true(vector_push(vector, "abcde"));
  assert_true(vector_push(vector, "ABCDE"));
  assert_true(vector_prepend(vector, "test"));

  assert_true(!vector_is_empty(vector));
  assert_num_equal(vector_size(vector), 4);
  assert_num_equal(vector_capacity(vector), 20);

  void **array = vector_to_array(vector);

  assert_string_equal(array[0], "test");
  assert_string_equal(array[1], "12345");
  assert_string_equal(array[2], "abcde");
  assert_string_equal(array[3], "ABCDE");

  assert_true(array[4] == NULL);

  vector_release(vector);
  free(array);
}

int main(){
  if(getenv("BENCHMARK_QTY"))
    if(getenv("BENCHMARK_ITEMS"))
      benchmark_impl();
  else
    test_run(test_impl);
  exit(0);
}
