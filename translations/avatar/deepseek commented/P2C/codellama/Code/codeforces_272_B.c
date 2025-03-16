#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

int main() {
    // Take input from the user
    char input[MAX_INPUT_LENGTH];
    fgets(input, MAX_INPUT_LENGTH, stdin);
    // Process the input and call nPairsWithCommonFX with the processed input
    return nPairsWithCommonFX(processInput(input));
}

int nPairsWithCommonFX(int* sequence, int length) {
    // Initialize a dictionary to store values grouped by their computed property
    int* storage = (int*)malloc(sizeof(int) * length);
    // List to store the computed property values
    int* FXs = (int*)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        // Compute the property for the current value
        int y = f(sequence[i]);
        // If the property is not already in storage, add it with the current value
        if (y < 0 || y >= length || storage[y] == 0) {
            storage[y] = sequence[i];
            FXs[i] = y;
        } else {
            // Otherwise, append the current value to the list of values for this property
            storage[y] += sequence[i];
            FXs[i] = y;
        }
    }
    // Calculate the number of pairs with common factor greater than 1
    int result = 0;
    for (int i = 0; i < length; i++) {
        int y = FXs[i];
        if (y >= 0 && y < length && storage[y] != 0) {
            result += (storage[y] * storage[y]) - storage[y];
        }
    }
    return result / 2;
}

int* processInput(char* input) {
    // Remove the trailing newline character
    input[strlen(input) - 1] = '\0';
    // Split the input into a list of integers
    int* sequence = (int*)malloc(sizeof(int) * strlen(input));
    int length = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        sequence[length++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return sequence;
}

int f(int n) {
    // Initialize y to 1, which will be the result for the property of n
    int y = 1;
    while (n != 1) {
        if (n % 2) {
            y += 1;
        }
        n /= 2;
    }
    return y;
}

// 