#include <stdio.h> // Include standard input/output library
#include <stdlib.h> // Include standard library for memory allocation
#include <string.h> // Include string library for string manipulation
#include <limits.h> // Include limits library for integer limits
#include <stdbool.h> // Include boolean library for using boolean values

// Define a structure to hold the integer and its count
typedef struct {
    int key; // The integer value
    int count; // The count of occurrences
} Pair;

// Function to find the index of a key in the array of pairs
int findIndex(Pair *pairs, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (pairs[i].key == key) {
            return i; // Return the index if the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    int n; // Variable to hold the number of integers
    scanf("%d", &n); // Read the number of integers from standard input

    Pair *pairs = malloc(n * sizeof(Pair)); // Allocate memory for pairs
    int size = 0; // Current size of the pairs array

    // Iterate through the given number of integers
    for (int i = 0; i < n; i++) {
        int val; // Variable to hold the current integer
        scanf("%d", &val); // Read the next integer from standard input

        // Check if the integer is already in the pairs array
        int index = findIndex(pairs, size, val);
        if (index != -1) {
            pairs[index].count++; // Increment the count if found
        } else {
            pairs[size].key = val; // Add new integer to pairs
            pairs[size].count = 1; // Initialize count to 1
            size++; // Increase the size of the pairs array
        }
    }

    // Initialize maximum value variable
    int max = INT_MIN;
    // Iterate through the pairs to find the maximum count
    for (int i = 0; i < size; i++) {
        if (pairs[i].count > max) {
            max = pairs[i].count; // Update maximum count
        }
    }

    // Print the maximum count and the size of the pairs array
    printf("%d %d\n", max, size);

    free(pairs); // Free the allocated memory
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
