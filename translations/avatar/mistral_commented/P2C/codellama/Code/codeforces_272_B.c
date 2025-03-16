#include <stdio.h>
#include <stdlib.h>

// This is the main function that takes input and calls the helper function nPairsWithCommonFX
int main() {
    // Read input from standard input
    int n;
    scanf("%d", &n);

    // Call the helper function with the sequence obtained from input
    int result = nPairsWithCommonFX(n);

    // Print the result
    printf("%d\n", result);

    return 0;
}

// This function takes a sequence as input and returns the number of pairs with common FX
int nPairsWithCommonFX(int n) {
    // Initialize an empty dictionary to store FX values and their corresponding values
    int storage[n];

    // Initialize an empty list to store unique FX values
    int FXs[n];

    // Initialize an index to store the number of unique FX values
    int FXsIndex = 0;

    // Iterate through each value in the sequence
    for (int i = 0; i < n; i++) {
        // Compute the FX value for the current value
        int fx = f(i);

        // If the FX value is not already in the dictionary, add it along with the value
        if (storage[fx] == 0) {
            storage[fx] = i;
            FXs[FXsIndex++] = fx;
        }

        // If the FX value is already in the dictionary, add the current value to the list of values for that FX
        else {
            storage[fx] = i;
        }
    }

    // Calculate the result using the formula given in the problem statement
    int result = (sum(len(storage[fx]) * len(storage[fx]) for fx in FXs) - sum(len(storage[fx]) for fx in FXs)) // 2;

    // Return the result
    return result;
}

// This function takes an integer as input and returns its FX value
int f(int n) {
    // Initialize a variable to store the FX value
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

// Run the main function if the script is executed directly
int main() {
    // Call the main function and print the result
    printf("%d\n", main());

    return 0;
}

