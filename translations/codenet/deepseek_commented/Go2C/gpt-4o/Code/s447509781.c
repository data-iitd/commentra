#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long max_sum(int n, long long *s) {
    bool *u = (bool *)calloc(n, sizeof(bool)); // Initialize a boolean array to track visited positions
    long long m = 0, f;

    // Iterate over possible values of c to find the maximum sum
    for (int c = 1; c < n - 1; c++) {
        f = 0;
        // Iterate over possible multiples of c
        for (int k = 0; c < n - 1 - k * c; k++) {
            u[k * c] = true; // Mark the position as visited
            if (u[n - 1 - k * c]) break; // If the position is already visited, break the loop
            f += s[n - 1 - k * c] + s[k * c]; // Add the values at the current positions
            if (m < f) m = f; // Update the maximum sum if the current sum is greater
        }
        // Reset the boolean array for the next value of c
        for (int k = 0; k * c < n - 1; k++) {
            u[k * c] = false;
        }
    }
    free(u); // Free the allocated memory for the boolean array
    return m; // Return the maximum sum found
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements
    long long *s = (long long *)malloc(n * sizeof(long long)); // Allocate memory for the array of integers
    for (int i = 0; i < n; i++) {
        scanf("%lld", &s[i]); // Read the array of integers
    }

    long long result = max_sum(n, s); // Calculate the maximum sum
    printf("%lld\n", result); // Print the maximum sum found

<<<<<<< HEAD
    free(s); // Free the allocated memory for the integer array
=======
    free(s); // Free the allocated memory for the array
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
