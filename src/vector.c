#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

// Private helper function to resize the vector.
static void vector_resize(Vector *vector, const size_t new_capacity) {
    int *new_data = realloc(vector->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed during resize.\n");
        exit(EXIT_FAILURE);
    }
    vector->data = new_data;
    vector->capacity = new_capacity;
}

Vector* vector_create(size_t initial_capacity) {
    Vector *vector = malloc(sizeof(Vector));
    if (vector == NULL) {
        fprintf(stderr, "Error: Failed to allocate vector struct.\n");
        return NULL;
    }

    if (initial_capacity == 0) {
        initial_capacity = 2;
    }

    vector->data = malloc(initial_capacity * sizeof(int));
    if (vector->data == NULL) {
        free(vector);
        fprintf(stderr, "Error: Failed to allocate vector data.\n");
        return NULL;
    }

    vector->size = 0;
    vector->capacity = initial_capacity;
    return vector;
}

void vector_destroy(Vector *vector) {
    if (vector == NULL) return;
    free(vector->data);
    free(vector);
}

void vector_insert(Vector *vector, const size_t index, const int value) {
    if (index > vector->size) {
        fprintf(stderr, "Error: Index %zu out of range for insertion.\n", index);
        return;
    }

    if (vector->size >= vector->capacity) {
        size_t new_capacity;

        if (vector->capacity < 2) {
            new_capacity = 2;
        } else {
            new_capacity = vector->capacity + (vector->capacity / 2);
        }
        vector_resize(vector, new_capacity);
    }

    // Shifting elements to the right.
    for (size_t i = vector->size; i > index; i--) {
        vector->data[i] = vector->data[i - 1];
    }

    vector->data[index] = value;
    vector->size++;
}

int vector_remove(Vector *vector, const size_t index) {
    if (index >= vector->size) {
        fprintf(stderr, "Error: Index %zu out of range for remove.\n", index);
        return -1;
    }

    int removed_value = vector->data[index];

    for (size_t i = index; i < vector->size - 1; i++) {
        vector->data[i] = vector->data[i + 1];
    }

    vector->size--;
    return removed_value;
}

void vector_push_back(Vector *vector, const int value) {
    vector_insert(vector, vector->size, value);
}

int vector_get(const Vector *vector, const size_t index) {
    if (index >= vector->size) {
        fprintf(stderr, "Error: Index %zu out of range for get.\n", index);
        return -1;
    }
    return vector->data[index];
}

int vector_pop_back(Vector *vector) {
    if (vector->size == 0) {
        fprintf(stderr, "Error: Vector is empty.\n");
        return -1;
    }
    return vector_remove(vector, vector->size -1);
}

size_t vector_size(const Vector *vector) {
    return vector->size;
}

size_t vector_capacity(const Vector *vector) {
    return vector->capacity;
}

void vector_update(const Vector *vector, const size_t index, const int value) {
    if (index >= vector->size) {
        fprintf(stderr,"Error, Index %zu out of range for update.\n", index);
        return;
    }
    vector->data[index] = value;
}

void vector_fit_memory(Vector *vector) {
    if (vector->size == vector-> capacity) return;

    size_t new_capacity;
    if(vector->size == 0) {
        new_capacity = 2;
    }else {
        new_capacity = vector->size;
    }
    vector_resize(vector, new_capacity);
}

bool vector_is_empty(const Vector *vector) {
    return (vector == NULL || vector->size == 0);
}

void vector_print(const Vector *vector) {
    if (vector == NULL) {
        printf("(null)\n");
        return;
    }

    printf("Vector (Size: %zu, Capacity: %zu): [ ", vector->size, vector->capacity);
    for (size_t i = 0; i < vector->size; i++) {
        printf("%d", vector->data[i]);
        if (i < vector->size -1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}