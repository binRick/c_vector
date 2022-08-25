#pragma once
///////////////////////////////////////////////////////////////#
#include <stdbool.h>
#include <stddef.h>
///////////////////////////////////////////////////////////////#

struct Vector;

struct Vector *vector_sort(struct Vector *, int (*sort_function)(const void *, const void *));

struct Vector *vector_new(void);
struct Vector *vector_new_with_options(const size_t /* initial_size */, const bool /* allow_resize */);
///////////////////////////////////////////////////////////////#
///////////////////////////////////////////////////////////////#

bool vector_is_released(struct Vector *);
bool vector_is_empty(struct Vector *);
size_t vector_size(struct Vector *);
size_t vector_capacity(struct Vector *);
bool  vector_is_allow_resize(struct Vector *);

bool vector_clear(struct Vector *);
void vector_release(struct Vector *);

bool vector_ensure_capacity(struct Vector *, const size_t /* size */);
bool vector_shrink(struct Vector *);

void **vector_to_array(struct Vector *);

bool vector_push(struct Vector *, void *);
void *vector_pop(struct Vector *);

void *vector_set(struct Vector *, size_t /* index */, void *);
void *vector_get(struct Vector *, size_t /* index */);
bool vector_prepend(struct Vector *, void *);

bool vector_insert(struct Vector *, size_t /* index */, void *);
void *vector_remove(struct Vector *, size_t /* index */);

///////////////////////////////////////////////////////////////#
typedef int (^vector_item_handler_block)(size_t, void *);
void vector_foreach(struct Vector *VECTOR, int (*HANDLER)(size_t INDEX, void *HANDLED_ITEM));
void vector_foreach_block(struct Vector *VECTOR, vector_item_handler_block cb);
///////////////////////////////////////////////////////////////#
#define VECTOR_FOREACH_AUTOCAST(VECTOR, TYPE, CALLBACK)    {       \
    vector_foreach_block(VECTOR, ^ int (size_t INDEX, void *ITEM){ \
      return(CALLBACK(INDEX, (TYPE)ITEM));                         \
    });                                                            \
}
///////////////////////////////////////////////////////////////#
