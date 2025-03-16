#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to compute the factor count
int f(int n) {
    int y = 1;
    while (n != 1) {
        if (n % 2) {
            y++;
        }
        n /= 2;
    }
    return y;
}

// Function to count pairs with common factors
int nPairsWithCommonFX(int *sequence, int size) {
    int *storage[MAX_SIZE] = {NULL}; // Array of pointers to store values based on their computed factor
    int FXs[MAX_SIZE] = {0};          // Array to keep track of unique factors
    int FX_count = 0;                 // Count of unique factors
    int i, j;

    // Iterate through each value in the input sequence
    for (i = 0; i < size; i++) {
        int value = sequence[i];
        int y = f(value); // Compute the factor for the current value

        // Check if the factor already exists in FXs
        int found = 0;
        for (j = 0; j < FX_count; j++) {
            if (FXs[j] == y) {
                found = 1;
                break;
            }
        }

        // If the factor is not already in FXs, add it
        if (!found) {
            FXs[FX_count++] = y; // Store the unique factor
            storage[y] = (int *)malloc(sizeof(int) * MAX_SIZE); // Allocate memory for values
            storage[y][0] = value; // Store the value under its factor
            storage[y][1] = 1; // Count of values under this factor
        } else {
            // If the factor already exists, append the value to the existing list
            storage[y][storage[y][1] + 1] = value; // Store the value
            storage[y][1]++; // Increment the count of values
        }
    }

    // Calculate the total number of pairs with common factors
    int total_pairs = 0;
    for (i = 0; i < FX_count; i++) {
        int count = storage[FXs[i]][1]; // Get the count of values for this factor
        total_pairs += count * count; // Count pairs
    }

    // Subtract the number of single occurrences
    for (i = 0; i < FX_count; i++) {
        total_pairs -= storage[FXs[i]][1];
    }

    return total_pairs / 2; // Return the final count of pairs
}

int main() {
    int sequence[MAX_SIZE];
    int n;

    // Read the number of elements
    scanf("%d", &n);
    
    // Read the input sequence
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    // Process the input sequence and print the number of pairs with common factors
    printf("%d\n", nPairsWithCommonFX(sequence, n));

    return 0;
}

// <END-OF-CODE>
