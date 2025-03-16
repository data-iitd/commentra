#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize an array 'm' to store the multipliers
    int m[] = {10, 50, 100, 500};
    int num[4]; // Array to store the numbers
    int first = 1; // Initialize a variable 'first' to check if it's the first iteration of the loop

    // Main loop to read the input money and calculate the change
    while (1) {
        int money;
        if (scanf("%d", &money) != 1 || money == 0) {
            break; // Exit the loop if input is not valid or money is 0
        }

        // If it's not the first iteration, print a newline character to separate the outputs
        if (!first) {
            printf("\n");
        }
        first = 0; // Set 'first' to false

        // Initialize variables 'sum'
        int sum = 0;

        // Read the numbers and calculate the sum of the products of each number and its corresponding multiplier
        for (int i = 0; i < 4; ++i) {
            scanf("%d", &num[i]); // Read the number
            sum += num[i] * m[i]; // Calculate the product and add it to the sum
        }

        // Calculate the change
        int change = sum - money;

        // Adjust the numbers to get the exact change
        for (int i = 3; i >= 0; --i) {
            // If the change is divisible by the current multiplier, subtract the required number of multipliers and update the change
            if (change / m[i]) {
                num[i] -= change / m[i];
                change %= m[i];
            }
        }

        // Print the numbers that still have a positive value
        for (int i = 0; i < 4; ++i) {
            if (num[i] > 0) {
                printf("%d %d\n", m[i], num[i]);
            }
        }
    }

    // Return EXIT_SUCCESS to indicate successful execution
    return EXIT_SUCCESS;
}

// <END-OF-CODE>
