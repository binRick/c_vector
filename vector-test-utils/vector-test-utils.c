#include "vector/vector.h"
#include "vector-test-utils/vector-test-utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static struct club_t clubs[] = {
  { "Aston Villa",             25 },
  { "Manchester City",         57 },
  { "Arsenal",                 40 },
  { "Everton",                 37 },
  { "West Ham United",         27 },
  { "Tottenham Hotspur",       41 },
  { "Wolverhampton Wanderers", 43 },
  { "Norwich City",            21 },
  { "Leicester City",          53 },
  { "Manchester United",       45 },
  { "Newcastle United",        35 },
  { "Brighton & Hove Albion",  29 },
  { "AFC Bournemouth",         27 },
  { "Crystal Palace",          39 },
  { "Sheffield United",        43 },
  { "Burnley",                 39 },
  { "Southampton",             34 },
  { "Watford",                 27 },
  { "Chelsea",                 48 },
  { "Liverpool",               82 },
  { 0 },
};

struct Vector *init_club_vector(){
  struct Vector *v   = vector_new();
  struct club_t *tmp = clubs;

  while (tmp->name) {
    vector_push(v, (void *)tmp);
    tmp++;
  }
  return(v);
}

void print_titled_club(char *t, struct Vector *V){
  printf("[%s] %lu items\n", t, vector_size(V));
  vector_foreach(V, print_club);
}

int print_club(size_t i, void *I){
  printf("Club #%lu: %s:%d\n", i,
         ((struct club_t *)I)->name,
         ((struct club_t *)I)->points
         );
  return(((i > 3) ? -1 : 0));
}

int print_item(size_t i, void *I){
  printf("Handling %lu: %s\n", i, (char *)I);
  return(((i > 3) ? -1 : 0));
}
struct Vector *init_vector1(){
  struct Vector *v = vector_new();
  size_t        i[10];

  i[0] = 12345;
  i[1] = 222222;
  i[2] = 3333333;
  vector_push(v, (void *)i[0]);
  vector_push(v, (void *)i[1]);
  vector_push(v, (void *)i[2]);
  return(v);
}

struct Vector *init_vector(){
  struct Vector *v = vector_new();
  char          *i[10];

  i[0] = "aaaaaaaaaaaaa";
  i[1] = "bbbbbbbbbbbbb";
  i[2] = "ccccccccccccc";
  i[3] = "dddddddddddd";
  i[4] = "eeeeeeeeEEEEE";
  i[5] = "ffffffffffff";
  vector_push(v, (void *)i[0]);
  vector_push(v, (void *)i[1]);
  vector_push(v, (void *)i[2]);
  vector_push(v, (void *)i[3]);
  vector_push(v, (void *)i[4]);
  vector_push(v, (void *)i[5]);
  return(v);
}

void test_run(void ( *fn )(void)){
  printf("Test ... ");
  fn();
  printf("Done\n");
}

void test_fail(){
  printf(" Error\n");
  exit(1);
}

void assert_true(bool value){
  if (!value) {
    test_fail();
  }
}

void assert_num_equal(size_t value1, size_t value2){
  if (value1 != value2) {
#ifdef linux
    printf("Assert Failed, value: %zu not equals to value: %zu", value1, value2);
#endif
    test_fail();
  }
}

void assert_string_equal(char *value1, char *value2){
  if (strcmp(value1, value2) != 0) {
    printf("Assert Failed, value: %s not equals to value: %s", value1, value2);
    test_fail();
  }
}
