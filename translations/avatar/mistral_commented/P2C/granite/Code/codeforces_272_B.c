
#include <stdio.h>
#include <stdlib.h>

// This function takes a sequence as input and returns the number of pairs with common FX
int nPairsWithCommonFX(int sequence[], int length) {
    // Initialize an empty dictionary to store FX values and their corresponding values
    int *storage = (int *)malloc(length * sizeof(int));
    int *FXs = (int *)malloc(length * sizeof(int));
    int fx, i, j, result = 0;

    // Iterate through each value in the sequence
    for (i = 0; i < length; i++) {
        // Compute the FX value for the current value
        fx = f(sequence[i]);

        // If the FX value is not already in the dictionary, add it along with the value
        if (storage[fx] == 0) {
            storage[fx] = sequence[i];
            FXs[fx] = 1;
        } else {
            FXs[fx]++;
        }
    }

    // Calculate the result using the formula given in the problem statement
    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if (f(sequence[i]) == f(sequence[j])) {
                result++;
            }
        }
    }

    // Free the memory allocated for the dictionary and FX values
    free(storage);
    free(FXs);

    // Return the result
    return result;
}

// This function takes an integer as input and returns its FX value
int f(int n) {
    // Initialize a variable to store the FX value
    int fx = 1;

    // Perform bitwise operations until the number is reduced to 1
    while (n!= 1) {
        // If the number is odd, increment the FX value
        if (n % 2) {
            fx++;
        }

        // Divide the number by 2 to reduce it further
        n /= 2;
    }

    // Return the final FX value
    return fx;
}

// This is the main function that takes input and calls the helper function nPairsWithCommonFX
int main() {
    // Read input from standard input
    int length;
    scanf("%d", &length);

    // Declare an array to store the sequence
    int sequence[length];

    // Read the sequence from standard input
    for (int i = 0; i < length; i++) {
        scanf("%d", &sequence[i]);
    }

    // Call the helper function with the sequence obtained from input
    int result = nPairsWithCommonFX(sequence, length);

    // Print the result
    printf("%d\n", result);

    // Return 0 to indicate successful execution
    return 0;
}

// Translate the above C code to Java and end with comment "