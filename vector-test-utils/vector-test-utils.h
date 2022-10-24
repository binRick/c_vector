#pragma once
#ifndef __TEST_H__
#define __TEST_H__
#include "vector/vector.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
//////////////////////////////////////
struct club_t {
  const char *name;
  int        points;
};
struct Vector *init_club_vector();
struct Vector *init_vector1();
struct Vector *init_vector();

int print_item(size_t i, void *I);
void print_titled_club(char *title, struct Vector *V);
int print_club(size_t i, void *I);

void test_run(void ( *fn )());
void test_fail();
void assert_true(bool);

void assert_num_equal(size_t, size_t);
void assert_string_equal(char *, char *);

#endif
