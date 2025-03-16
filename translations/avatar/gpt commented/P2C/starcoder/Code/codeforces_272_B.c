#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read input from the user (not stored, just consumed)
    scanf("%*s");
    // Process the input sequence and return the number of pairs with common factors
    return nPairsWithCommonFX(map(int, input().split()));
}

int nPairsWithCommonFX(int sequence[]) {
    // Initialize a dictionary to store values based on their computed factor
    int storage[1000000];
    // List to keep track of unique factors
    int FXs[1000000];
    
    // Iterate through each value in the input sequence
    for (int i = 0; i < sizeof(sequence) / sizeof(sequence[0]); i++) {
        // Compute the factor for the current value
        int y = f(sequence[i]);
        // If the factor is not already in storage, add it
        if (storage[y] == 0) {
            storage[y] = 1;  // Store the value under its factor
            FXs[i] = y;      // Keep track of the unique factor
        } else {
            // If the factor already exists, append the value to the existing list
            storage[y] += 1;
        }
    }
    
    // Calculate the total number of pairs with common factors
    // The formula counts pairs and subtracts the number of single occurrences
    int nPairs = 0;
    for (int i = 0; i < sizeof(FXs) / sizeof(FXs[0]); i++) {
        nPairs += storage[FXs[i]] * storage[FXs[i]];
    }
    return (nPairs - sum(storage)) / 2;
}

int f(int n) {
    // Initialize the factor count
    int y = 1;
    // Loop until n is reduced to 1
    while (n!= 1) {
        // If n is odd, increment the factor count
        if (n % 2) {
            y += 1;
        }
        // Divide n by 2 to reduce it
        n /= 2;
    }
    // Return the total count of factors
    return y;
}

int sum(int storage[]) {
    int s = 0;
    for (int i = 0; i < sizeof(storage) / sizeof(storage[0]); i++) {
        s += storage[i];
    }
    return s;
}

