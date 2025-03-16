#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long max_sum(int n, long long *s) {
    bool *u = (bool *)calloc(n, sizeof(bool)); // Allocate memory for used indices
    long long m = 0, f;

    // Iterate through possible values of c from 1 to n-2
    for (int c = 1; c < n - 1; c++) {
        f = 0; // Reset the temporary sum for each c

        // Iterate to find pairs of indices based on the current value of c
        for (int k = 0; k < (n - 1) / c; k++) {
            u[k * c] = true; // Mark the current index as used

            // Break if the corresponding index is already used
            if (u[n - 1 - k * c]) break;

            // Calculate the sum of the elements at the current indices
            f += s[n - 1 - k * c] + s[k * c];

            // Update the maximum sum if the current sum is greater
            if (m < f) m = f;
        }

        // Reset the used indices for the next iteration of c
        for (int k = 0; k * c < n - 1; k++) {
            u[k * c] = false;
        }
    }

    free(u); // Free the allocated memory for used indices
    return m; // Return the maximum sum found
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements

    long long *s = (long long *)malloc(n * sizeof(long long)); // Allocate memory for the array of integers
    for (int i = 0; i < n; i++) {
        scanf("%lld", &s[i]); // Read each integer into the array
    }

    long long result = max_sum(n, s); // Calculate the maximum sum
    printf("%lld\n", result); // Print the maximum sum found

    free(s); // Free the allocated memory for the array
    return 0;
}

// <END-OF-CODE>
