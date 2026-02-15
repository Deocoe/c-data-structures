#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h> // For size_t
#include <stdbool.h>

// Vector type definition.
typedef struct {
    int *data;          // Pointer to the data array
    size_t size;        // Current number of elements
    size_t capacity;    // Total capacity → Allocated Memory
} Vector;

// --- Management Functions ---

// Creates a new vector with a specific initial capacity.
Vector* vector_create(size_t initial_capacity);

// Free all memory associated with the vector.
void vector_destroy(Vector *vector);

// --- Access and Modification Functions ---

// Inserts an element at a specific index,
// moving existing elements to the right to make space.
void vector_insert(Vector *vector, size_t index, int value);

// Removes the element at a specific index,
// moving subsequent elements to the left to fill the gap,
// returns -1 on error.
int vector_remove(Vector *vector, size_t index);

// Inserts an element to the end.
void vector_push_back(Vector *vector, int value);

// Returns the element at a specific index,
// returns -1 on error.
int vector_get(const Vector *vector, size_t index);

// Removes the last element and returns it,
// returns -1 on error.
int vector_pop_back(Vector *vector);

// Returns the current number of elements.
size_t vector_size(const Vector *vector);

// Returns the current capacity.
size_t vector_capacity(const Vector *vector);

// Updates the value at a specific index.
void vector_update(const Vector *vector, size_t index, int value);

// Reduces capacity to the current size, reducing memory usage.
void vector_fit_memory(Vector *vector);

// Verify is the vector is empty,
// 1 for empty, 0 for not-empty.
bool vector_is_empty(const Vector *vector);

// Prints the vector content.
void vector_print(const Vector *vector);



#endif //VECTOR_H