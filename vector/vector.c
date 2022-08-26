#include "vector/vector.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
///////////////////////////
struct Vector {
  bool   released;
  size_t size;
  size_t capacity;
  void   **buffer;
  bool   allow_resize;
};
///////////////////////////
static bool _vector_clear(struct Vector *);
static bool _vector_set_capacity_with_buffer(struct Vector *, size_t);
static bool _vector_set_capacity(struct Vector *, size_t);
size_t vector_size(struct Vector *vector);
///////////////////////////

struct Vector *vector_new_with_options(const size_t initial_size, const bool allow_resize){
  size_t size = 1;

  if (initial_size > 0) {
    size = initial_size;
  }

  struct Vector *vector = malloc(sizeof(struct Vector));

  if (vector == NULL) {
    return(NULL);
  }

  vector->released = false;
  vector->size     = 0;
  vector->capacity = size;

  vector->buffer = NULL;
  if (!_vector_clear(vector)) {
    vector_release(vector);
    return(NULL);
  }

  // set lock/unlock to the max size
  vector->allow_resize = allow_resize;

  return(vector);
}

struct Vector *vector_new(){
  return(vector_new_with_options(20, true));
}

bool vector_is_released(struct Vector *vector){
  return(vector == NULL || vector->released);
}

bool vector_is_empty(struct Vector *vector){
  return(vector->size == 0);
}

size_t vector_size(struct Vector *vector){
  return(vector->size);
}

size_t vector_capacity(struct Vector *vector){
  return(vector->capacity);
}

bool  vector_is_allow_resize(struct Vector *vector){
  return(vector->allow_resize);
}

bool vector_clear(struct Vector *vector){
  if (vector_is_released(vector)) {
    return(false);
  }

  // already empty
  if (vector->size == 0) {
    return(true);
  }

  return(_vector_clear(vector));
}

void vector_release(struct Vector *vector){
  if (vector_is_released(vector)) {
    return;
  }

  if (vector->buffer != NULL) {
    free(vector->buffer);
    vector->buffer = NULL;
  }

  vector->released = true;

  free(vector);
}

bool vector_ensure_capacity(struct Vector *vector, const size_t size){
  if (vector_is_released(vector)) {
    return(false);
  }

  if (size <= vector->capacity) {
    return(true);
  }

  return(_vector_set_capacity(vector, size));
}

bool vector_shrink(struct Vector *vector){
  if (vector_is_released(vector)) {
    return(false);
  }

  if (vector->size == vector->capacity) {
    return(true);
  }

  return(_vector_set_capacity(vector, vector->size));
}

void **vector_to_array(struct Vector *vector){
  if (vector_is_released(vector)) {
    return(NULL);
  }

  void **buffer = calloc((vector->size + 1), sizeof(void *));
  buffer[vector->size] = 0;

  for (size_t index = 0; index < vector->size; index++) {
    buffer[index] = vector->buffer[index];
  }

  return(buffer);
}

bool vector_push(struct Vector *vector, void *item){
  if (vector_is_released(vector)) {
    return(false);
  }

  return(vector_insert(vector, vector->size, item));
}

void *vector_pop(struct Vector *vector){
  if (vector_is_released(vector)) {
    return(NULL);
  }

  if (vector->size == 0) {
    return(NULL);
  }

  return(vector_remove(vector, vector->size - 1));
}

void *vector_set(struct Vector *vector, size_t index, void *item){
  if (vector_is_released(vector)) {
    return(NULL);
  }

  if (!_vector_set_capacity_with_buffer(vector, index + 1)) {
    return(NULL);
  }

  void *old_value = vector->buffer[index];
  vector->buffer[index] = item;

  if (index >= vector->size) {
    vector->size = index + 1;
  }

  return(old_value);
}

void *vector_get(struct Vector *vector, size_t index){
  if (vector_is_released(vector)) {
    return(NULL);
  }

  if (vector->size <= index) {
    return(NULL);
  }

  return(vector->buffer[index]);
}

bool vector_prepend(struct Vector *vector, void *item){
  return(vector_insert(vector, 0, item));
}

bool vector_insert(struct Vector *vector, size_t index, void *item){
  if (vector_is_released(vector)) {
    return(false);
  }

  size_t min_size = index + 1;
  if (min_size <= vector->size) {
    min_size = vector->size + 1;
  }
  if (!_vector_set_capacity_with_buffer(vector, min_size)) {
    return(false);
  }

  if (vector->size == index) {
    vector->buffer[vector->size] = item;
    vector->size++;
  }else if (vector->size < index) {
    vector->buffer[index] = item;
    vector->size          = index + 1;
  }else {
    if (vector->size > 0) {
      // shift items
      for (size_t shift_index = vector->size; shift_index-- > index; ) {
        vector->buffer[shift_index + 1] = vector->buffer[shift_index];
      }
    }

    vector->buffer[index] = item;
    vector->size++;
  }

  return(true);
} /* vector_insert */

void *vector_remove(struct Vector *vector, size_t index){
  if (vector_is_released(vector)) {
    return(NULL);
  }

  if (vector->size <= index) {
    return(NULL);
  }

  void *old_value = vector->buffer[index];

  // shift items
  for (size_t shift_index = index; shift_index < vector->size; shift_index++) {
    vector->buffer[shift_index] = vector->buffer[shift_index + 1];
  }

  vector->size--;

  return(old_value);
}

static bool _vector_clear(struct Vector *vector){
  if (vector_is_released(vector)) {
    return(false);
  }

  if (vector->buffer != NULL) {
    free(vector->buffer);
    vector->buffer = NULL;
  }

  vector->size = 0;

  vector->buffer = malloc((vector->capacity + 1) * sizeof(void *));
  if (vector->buffer == NULL) {
    vector_release(vector);
    return(false);
  }

  for (size_t index = 0; index < vector->capacity; index++) {
    vector->buffer[index] = NULL;
  }

  vector->buffer[vector->capacity] = 0;

  return(true);
}

static bool _vector_set_capacity_with_buffer(struct Vector *vector, size_t min_size){
  if (min_size > vector->capacity) {
    size_t new_size = vector->size * 2;
    if (min_size > new_size) {
      new_size = min_size * 2;
    }
    if (!_vector_set_capacity(vector, new_size)) {
      return(false);
    }
  }

  return(true);
}

static bool _vector_set_capacity(struct Vector *vector, const size_t size){
  if (!vector->allow_resize) {
    return(false);
  }

  size_t old_capacity = vector->capacity;

  vector->capacity = size;
  vector->buffer   = realloc(vector->buffer, (vector->capacity + 1) * sizeof(void *));

  for (size_t index = old_capacity; index < vector->capacity; index++) {
    vector->buffer[index] = NULL;
  }

  // put null at end
  vector->buffer[vector->capacity] = 0;

  return(true);
}

void vector_foreach_block(struct Vector *VECTOR, vector_item_handler_block cb){
  for (size_t __i__ = 0; __i__ < vector_size(VECTOR); __i__++) {
    int b = cb(__i__, (void *)vector_get(VECTOR, __i__));
    if (b == -1) {
      break;
    }
  }
}

void vector_foreach(struct Vector *VECTOR, int (*HANDLER)(size_t INDEX, void *HANDLED_ITEM)){
  for (size_t __i__ = 0; __i__ < vector_size(VECTOR); __i__++) {
    int b = HANDLER(__i__, (void *)vector_get(VECTOR, __i__));
    if (b == -1) {
      break;
    }
  }
}

struct Vector *vector_filter_new(struct Vector *VECTOR, vector_item_filter cb){
  struct Vector *NEW_VECTOR = vector_new();

  for (size_t __i__ = 0; __i__ < vector_size(VECTOR); __i__++) {
    if (true == cb(__i__, (void *)vector_get(VECTOR, __i__))) {
      vector_push(NEW_VECTOR, (void *)vector_get(VECTOR, __i__));
    }
  }
  return(NEW_VECTOR);
}

struct Vector *vector_filter_mut(struct Vector *VECTOR, vector_item_filter cb){
  for (size_t __i__ = 0; __i__ < vector_size(VECTOR); __i__++) {
    if (false == cb(__i__, (void *)vector_get(VECTOR, __i__))) {
      vector_remove(VECTOR, __i__);
    }
  }
  return(VECTOR);
}
