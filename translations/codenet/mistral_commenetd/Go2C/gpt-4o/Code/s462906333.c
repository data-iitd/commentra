#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Constants
const int inf = 1e14;

// Function to read an integer from input
int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to find the minimum of multiple integers
int min(int a, int b) {
    return a < b ? a : b;
}

// Main function
int main() {
    // Reading input
    int n = readInt();
    int x = readInt();

    // Initializing arrays
    int *a = (int *)malloc(n * sizeof(int));
    int *v = (int *)malloc(n * sizeof(int));

    // Reading array elements
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
        v[i] = a[i]; // Initialize v with values from a
    }

    // Initializing answer variable
    long long ans = inf;

    // Iterating through all possible subarrays
    for (int k = 0; k < n; k++) {
        // Initializing variable to store sum of subarray elements
        long long kans = 0;

        // Iterating through all elements of the subarray
        for (int i = 0; i < n; i++) {
            // Checking if current index is out of bounds for subarray
            if (i - k < 0) {
                // Updating current element in subarray with minimum of itself and corresponding element from the main array
                v[i] = min(v[i], a[n + i - k]);
            } else {
                // Updating current element in subarray with minimum of itself and previous element in subarray
                v[i] = min(v[i], a[i - k]);
            }

            // Adding current element to the sum of subarray
            kans += v[i];
        }

        // Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
        ans = min(ans, kans + k * x);
    }

    // Printing the answer
    printf("%lld\n", ans);

    // Free allocated memory
    free(a);
    free(v);

    return 0;
}

// <END-OF-CODE>
