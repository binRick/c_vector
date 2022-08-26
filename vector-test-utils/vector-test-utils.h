#pragma once
//////////////////////////////////////
#include "c_vector/vector/vector.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
struct club_t {
  const char *name;
  int        points;
};
int print_item(size_t i, void *I);
void print_titled_club(char *title, struct Vector *V);
int print_club(size_t i, void *I);
struct Vector *init_club_vector();
struct Vector *init_vector1();
struct Vector *init_vector();
