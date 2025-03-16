
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read input from the user (not stored, just consumed)
    int n;
    scanf("%d", &n);
    // Process the input sequence and return the number of pairs with common factors
    return nPairsWithCommonFX(n);
}

int nPairsWithCommonFX(int n) {
    // Initialize a dictionary to store values based on their computed factor
    int storage[n + 1];
    // List to keep track of unique factors
    int FXs[n + 1];
    int FXs_len = 0;
    
    // Iterate through each value in the input sequence
    for (int i = 0; i < n; i++) {
        // Compute the factor for the current value
        int y = f(i);
        // If the factor is not already in storage, add it
        if (storage[y] == 0) {
            storage[y] = i + 1;  // Store the value under its factor
            FXs[FXs_len++] = y;  // Keep track of the unique factor
        } else {
            // If the factor already exists, append the value to the existing list
            storage[y] = -1;
        }
    }
    
    // Calculate the total number of pairs with common factors
    // The formula counts pairs and subtracts the number of single occurrences
    int result = 0;
    for (int i = 0; i < FXs_len; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (storage[FXs[i]] == j + 1) {
                count++;
            }
        }
        result += count * count;
    }
    return (result - FXs_len) / 2;
}

int f(int n) {
    // Initialize the factor count
    int y = 1;
    // Loop until n is reduced to 1
    while (n!= 1) {
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

// END-OF-CODE