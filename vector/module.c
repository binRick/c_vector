#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
///////////////////////////////
#include "vector/module.h"
#include "vector/vector.h"
///////////////////////////////

int vector_module_init(module(vector_module) *exports) {
  printf("vector init>\n");
  clib_module_init(vector_module, exports);
  exports->pid = getpid();
  return(0);
}

void vector_module_deinit(module(vector_module) *exports) {
  printf("<%d> vector deinit>\n", exports->pid);
}
