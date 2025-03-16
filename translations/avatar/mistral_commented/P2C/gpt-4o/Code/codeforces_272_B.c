#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to compute the FX value
int f(int n) {
    int fx = 1;
    while (n != 1) {
        if (n % 2) {
            fx++;
        }
        n /= 2;
    }
    return fx;
}

// Function to count pairs with common FX
int nPairsWithCommonFX(int *sequence, int size) {
    int storage[MAX_SIZE] = {0}; // Array to store counts of FX values
    int FXs[MAX_SIZE] = {0}; // Array to store unique FX values
    int fxCount = 0; // Count of unique FX values

    // Iterate through each value in the sequence
    for (int i = 0; i < size; i++) {
        int fx = f(sequence[i]);

        // If the FX value is not already counted, add it
        if (storage[fx] == 0) {
            FXs[fxCount++] = fx;
        }
        storage[fx]++;
    }

    // Calculate the result using the formula given in the problem statement
    int result = 0;
    for (int i = 0; i < fxCount; i++) {
        result += storage[FXs[i]] * storage[FXs[i]];
    }
    for (int i = 0; i < fxCount; i++) {
        result -= storage[FXs[i]];
    }
    result /= 2;

    return result;
}

// Main function
int main() {
    int sequence[MAX_SIZE];
    int size = 0;

    // Read input from standard input
    while (scanf("%d", &sequence[size]) != EOF) {
        size++;
    }

    // Call the helper function with the sequence obtained from input
    int result = nPairsWithCommonFX(sequence, size);

    // Print the result
    printf("%d\n", result);

    return 0;
}

// <END-OF-CODE>
