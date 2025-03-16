#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Disable synchronization with C I/O for faster input/output
    setbuf(stdout, NULL);

    // Initialize a vector to hold the denominations of money
    int m[4] = {10, 50, 100, 500};

    bool first = true; // Flag to handle formatting of output
    // Read money input until EOF or invalid input
    for(int money; scanf("%d", &money) == 1 && money;) {
        // Print a newline before the output of subsequent transactions
        if(!first)
            printf("\n");

        first = false; // Set the flag to false after the first input
        int sum = 0; // Initialize sum to calculate total value of coins
        int num[4]; // Vector to hold the number of each denomination

        // Read the number of coins for each denomination and calculate the total sum
        for(int i = 0; i < 4; ++i) {
            scanf("%d", &num[i]); // Input the number of coins for the current denomination
            sum += num[i] * m[i]; // Update the total sum
        }

        // Calculate the change to be returned
        int change = sum - money;

        // Calculate how many coins of each denomination to return as change
        for(int i = 3; i >= 0; --i) {
            if(change / m[i]) { // Check if the current denomination can be used for change
                num[i] = num[i] - change / m[i]; // Reduce the number of coins of this denomination
                change %= m[i]; // Update the remaining change to be returned
            }
        }

        // Output the remaining coins of each denomination that are greater than zero
        for(int i = 0; i < 4; ++i)
            if(num[i] > 0) // Only print denominations that still have coins left
                printf("%d %d\n", m[i], num[i]); // Print denomination and count
    }

    return EXIT_SUCCESS; // Return success status
}

