#include <stdio.h>
#include <stdlib.h>

// This function takes an integer as input and returns its FX value
int f(int n) {
    int fx = 1;

    // Perform bitwise operations until the number is reduced to 1
    while (n != 1) {
        // If the number is odd, increment the FX value
        if (n % 2) {
            fx += 1;
        }

        // Divide the number by 2 to reduce it further
        n /= 2;
    }

    // Return the final FX value
    return fx;
}

// This function takes a sequence as input and returns the number of pairs with common FX
int nPairsWithCommonFX(int* sequence, int size) {
    // Initialize an empty dictionary to store FX values and their corresponding values
    int storage[100001] = {0}; // Assuming the maximum FX value is 100000

    // Initialize an empty list to store unique FX values
    int FXs[100001] = {0};
    int FXsSize = 0;

    // Iterate through each value in the sequence
    for (int i = 0; i < size; i++) {
        int value = sequence[i];

        // Compute the FX value for the current value
        int fx = f(value);

        // If the FX value is not already in the dictionary, add it along with the value
        if (storage[fx] == 0) {
            storage[fx] = value;
            FXs[FXsSize++] = fx;
        }

        // If the FX value is already in the dictionary, add the current value to the list of values for that FX
        else {
            storage[fx] = value;
        }
    }

    // Calculate the result using the formula given in the problem statement
    int result = 0;
    for (int i = 0; i < FXsSize; i++) {
        int fx = FXs[i];
        result += (storage[fx] * storage[fx]);
    }
    result = (result - FXsSize) / 2;

    // Return the result
    return result;
}

// The main function that takes input and calls the helper function nPairsWithCommonFX
int main() {
    int size;
    scanf("%d", &size); // Read the size of the sequence

    // Read the sequence from standard input
    int* sequence = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &sequence[i]);
    }

    // Call the helper function with the sequence obtained from input
    int result = nPairsWithCommonFX(sequence, size);

    // Print the result
    printf("%d\n", result);

    // Free the allocated memory
    free(sequence);

    return 0;
}
