#include <stdio.h>
#include <stdlib.h>

// This function takes a sequence as input and returns the number of pairs with common FX
int nPairsWithCommonFX(int *sequence, int size) {
    // Initialize an empty dictionary to store FX values and their corresponding values
    int *storage = (int *)malloc(sizeof(int) * size);
    int *FXs = (int *)malloc(sizeof(int) * size);

    // Initialize an empty list to store unique FX values
    int nFXs = 0;

    // Iterate through each value in the sequence
    for (int i = 0; i < size; i++) {
        // Compute the FX value for the current value
        int fx = f(sequence[i]);

        // If the FX value is not already in the dictionary, add it along with the value
        if (storage[fx] == 0) {
            storage[fx] = 1;
            FXs[nFXs++] = fx;
        }

        // If the FX value is already in the dictionary, add the current value to the list of values for that FX
        else {
            storage[fx]++;
        }
    }

    // Calculate the result using the formula given in the problem statement
    int result = (sum(storage[fx] * storage[fx] for (int i = 0; i < nFXs; i++) {
        storage[fx]
    }) - sum(storage[fx] for (int i = 0; i < nFXs; i++) {
        storage[fx]
    })) / 2;

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

// Run the main function if the script is executed directly
int main() {
    // Read input from standard input
    int size;
    scanf("%d", &size);

    // Read the sequence from standard input
    int *sequence = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &sequence[i]);
    }

    // Call the helper function with the sequence obtained from input
    int result = nPairsWithCommonFX(sequence, size);

    // Print the result
    printf("%d\n", result);

    // Free the memory allocated to the sequence
    free(sequence);

    // Return from the main function
    return 0;
}

