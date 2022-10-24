#include "vector/vector.h"
////////////////////////////////////
struct club_t {
  const char *name;
  int        points;
};
////////////////////////////////////
int print_item(size_t i, void *I);
int print_club(size_t i, void *I);
////////////////////////////////////
struct Vector *init_club_vector();
struct Vector *init_vector1();
struct Vector *init_vector();
////////////////////////////////////
