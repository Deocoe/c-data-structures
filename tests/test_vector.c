#include "vector.h"
#include <stdio.h>
#include <assert.h>

int main() {
    printf("--- Testing Dynamic Vector ---\n");

    // 1 - Creation & Initial State
    Vector *vector = vector_create(2);
    assert(vector != NULL);
    assert(vector_is_empty(vector) == true);
    printf("Initial State: ");
    vector_print(vector);

    // 2 - Push Back & Growth (1.5x factor)
    vector_push_back(vector, 10);
    vector_push_back(vector, 20);
    // Next push triggers resize: 2 + (2/2) = 3
    vector_push_back(vector, 30);

    printf("\nAfter pushes (Resize expected): ");
    vector_print(vector);
    assert(vector_size(vector) == 3);
    assert(vector_capacity(vector) == 3);

    // 3 - Insertions (Middle and Head)
    printf("\nInserting 15 at index 1 and 5 at head:\n");
    vector_insert(vector, 1, 15); // [10, 15, 20, 30]
    vector_insert(vector, 0, 5);  // [5, 10, 15, 20, 30]
    vector_print(vector);
    assert(vector_get(vector, 0) == 5);
    assert(vector_get(vector, 2) == 15);

    // 4 - Updates (vector_update)
    printf("\nUpdating index 2 to 99:\n");
    vector_update(vector, 2, 99);
    vector_print(vector);
    assert(vector_get(vector, 2) == 99);

    // 5 - Removal & Pop Back
    printf("\nRemoving from index 1 and popping back:\n");
    int removed = vector_remove(vector, 1); // Removes 10
    int popped = vector_pop_back(vector);   // Removes 30
    vector_print(vector);
    assert(removed == 10);
    assert(popped == 30);
    assert(vector_size(vector) == 3); // Should be [5, 99, 20]

    // 6 - Memory Optimization (vector_fit_memory)
    printf("\nFitting memory (Capacity should drop to Size):\n");
    printf("Before: Size %zu, Capacity %zu\n", vector_size(vector), vector_capacity(vector));
    vector_fit_memory(vector);
    printf("After:  Size %zu, Capacity %zu\n", vector_size(vector), vector_capacity(vector));
    assert(vector_size(vector) == vector_capacity(vector));




    // 7 - NEGATIVE TESTS (Testing Boundaries)
    printf("\n--- Testing Edge Cases (Errors Expected) ---\n");

    // Get out of range
    int out_val = vector_get(vector, 100);
    assert(out_val == -1);

    // Update out of range
    vector_update(vector, 50, 0);

    // Insert in a "gap" (Size is 3, trying to insert at 10)
    vector_insert(vector, 10, 500);
    assert(vector_size(vector) == 3);

    // 8 - Emptying the vector
    printf("\nEmptying vector and testing fit_memory on empty:\n");
    vector_pop_back(vector);
    vector_pop_back(vector);
    vector_pop_back(vector);
    assert(vector_is_empty(vector) == true);

    vector_fit_memory(vector); // Should set capacity to 2 (minimum)
    assert(vector_capacity(vector) == 2);
    vector_print(vector);

    // 9 - Destroying
    vector_destroy(vector);
    printf("\nAll tests passed successfully!\n");

    return 0;
}