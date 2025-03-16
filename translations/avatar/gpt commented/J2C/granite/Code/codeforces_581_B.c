
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a static array to hold long values (not used in this code)
    static long set[100000];

    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Initialize an array to hold the input values
    long a[n];

    // Populate the array with input values
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }

    // Initialize a dp array to store the maximum values
    long dp[n + 1];

    // Fill the dp array with -1 to indicate uninitialized values
    for (int i = 0; i < n + 1; i++) {
        dp[i] = -1;
    }

    // Set the last element of dp to the last element of a
    dp[n - 1] = a[n - 1];

    // Fill the dp array with the maximum values from the end to the beginning
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = (dp[i + 1] > a[i])? dp[i + 1] : a[i];
    }

    // Iterate through the original array to calculate the output
    for (int i = 0; i < n; i++) {
        // If the current element is greater than the next maximum, print 0
        if (a[i] > dp[i + 1]) {
            printf("0 ");
        }
        // Otherwise, calculate and print the difference to the next maximum
        else {
            printf("%ld ", dp[i + 1] - a[i] + 1);
        }
    }

    // Print a new line after all outputs
    printf("\n");

    return 0;
}

// Debugging utility to print objects
void debug(void) {
    printf("DEBUG\n");
}

// End of code
