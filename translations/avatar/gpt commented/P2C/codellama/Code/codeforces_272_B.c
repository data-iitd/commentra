#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000000

int main() {
    // Read input from the user (not stored, just consumed)
    char input[MAX_INPUT_SIZE];
    fgets(input, MAX_INPUT_SIZE, stdin);
    // Process the input sequence and return the number of pairs with common factors
    printf("%d\n", nPairsWithCommonFX(input));
    return 0;
}

int nPairsWithCommonFX(char *input) {
    // Initialize a dictionary to store values based on their computed factor
    int storage[1000000];
    // List to keep track of unique factors
    int FXs[1000000];
    int nFXs = 0;
    
    // Iterate through each value in the input sequence
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Compute the factor for the current value
        int y = f(atoi(token));
        // If the factor is not already in storage, add it
        if (storage[y] == 0) {
            storage[y] = 1;  // Store the value under its factor
            FXs[nFXs++] = y; // Keep track of the unique factor
        } else {
            // If the factor already exists, increment the count
            storage[y]++;
        }
        // Get the next token
        token = strtok(NULL, " ");
    }
    
    // Calculate the total number of pairs with common factors
    // The formula counts pairs and subtracts the number of single occurrences
    int nPairs = 0;
    for (int i = 0; i < nFXs; i++) {
        nPairs += storage[FXs[i]] * (storage[FXs[i]] - 1);
    }
    return nPairs / 2;
}

int f(int n) {
    // Initialize the factor count
    int y = 1;
    // Loop until n is reduced to 1
    while (n != 1) {
        // If n is odd, increment the factor count
        if (n % 2) {
            y++;
        }
        // Divide n by 2 to reduce it
        n /= 2;
    }
    // Return the total count of factors
    return y;
}

