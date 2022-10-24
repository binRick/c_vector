#pragma once
#ifndef __VECTOR_H
#define __VECTOR_H
///////////////////////////////////////////////////////////////#
#include <stdbool.h>
#include <stddef.h>
///////////////////////////////////////////////////////////////#

struct Vector;

struct Vector *vector_new(void);
struct Vector *vector_new_with_options(const size_t /* initial_size */, const bool /* allow_resize */);
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
struct Vector *vector_from_array(void **items, size_t item_bytes, size_t qty);

bool vector_push(struct Vector *, void *);
void *vector_pop(struct Vector *);

void *vector_set(struct Vector *, size_t /* index */, void *);
void *vector_get(struct Vector *, size_t /* index */);
bool vector_prepend(struct Vector *, void *);

bool vector_insert(struct Vector *, size_t /* index */, void *);
void *vector_remove(struct Vector *, size_t /* index */);

///////////////////////////////////////////////////////////////#
void vector_foreach(struct Vector *VECTOR, int (*HANDLER)(size_t INDEX, void *HANDLED_ITEM));
void vector_foreach_block(struct Vector *VECTOR, int (^cb)(size_t, void *));
size_t vector_filter_size(struct Vector *VECTOR, bool (^cb)(size_t, void *));
struct Vector *vector_filter_new(struct Vector *VECTOR, bool (^cb)(size_t, void *));
struct Vector *vector_filter_mut(struct Vector *VECTOR, bool (^cb)(size_t, void *));
///////////////////////////////////////////////////////////////#
#define vector_foreach_cast(VECTOR, TYPE, CALLBACK)    {           \
    vector_foreach_block(VECTOR, ^ int (size_t INDEX, void *ITEM){ \
      return(^ int CALLBACK(INDEX, (TYPE)ITEM));                   \
    });                                                            \
}
///////////////////////////////////////////////////////////////#
#define vector_foreach_cast1(VECTOR, TYPE, CB)         {           \
    vector_foreach_block(VECTOR, ^ int (size_t INDEX, void *ITEM){ \
      return(CB((size_t)INDEX, (TYPE)ITEM));                       \
    });                                                            \
}
///////////////////////////////////////////////////////////////#
struct Vector *vector_sort(struct Vector *, int (*sort_function)(const void *, const void *));

#include "hash/hash.h"
hash_t *vector_to_hash_values(struct Vector *);
struct Vector *hash_keys_to_vector(hash_t *h);
struct Vector *hash_values_to_vector(hash_t *h);


#endif
