#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_N 10000

// Function to find the minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}

// Function to find the minimum of three integers
int min3(int a, int b, int c) {
    return min(min(a, b), c);
}

// Function to read an integer from input
int readInt() {
<<<<<<< HEAD
    int value;
    scanf("%d", &value);
    return value;
=======
    int x;
    scanf("%d", &x);
    return x;
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    // Read the number of elements and the value of x
    int n = readInt();
    int x = readInt();

    // Create an array to hold the input integers
    int a[MAX_N];
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
    }

    // Create a copy of the array a for manipulation
    int v[MAX_N];
    memcpy(v, a, n * sizeof(int));

    // Initialize the answer to infinity
    long long ans = LLONG_MAX;

    // Iterate over each possible k value
    for (int k = 0; k < n; k++) {
        long long kans = 0; // Initialize the current answer for this k

        // Calculate the minimum values for the current k
        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                // If i-k is out of bounds, use the wrapped index
                v[i] = min(v[i], a[(n + i - k) % n]);
            } else {
                // Otherwise, use the normal index
                v[i] = min(v[i], a[i - k]);
            }
            // Accumulate the current answer
            kans += v[i];
        }

        // Update the overall answer with the minimum found so far
        ans = min(ans, kans + k * (long long)x);
    }

    // Print the final answer
    printf("%lld\n", ans);

    return 0;
}

// <END-OF-CODE>
