#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Function prototypes
int min(int a, int b);
int readInt();

int main() {
    // Read the number of elements and the value of x
    int n = readInt();
    int x = readInt();

    // Create a slice to hold the input integers
    int a[n];

    // Read n integers into the array a
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
    }

    // Initialize the answer to infinity
    int ans = INF;

    // Iterate over each possible k value
    for (int k = 0; k < n; k++) {
        int kans = 0; // Initialize the current answer for this k

        // Create a copy of the array a for manipulation
        int v[n];
        for (int i = 0; i < n; i++) {
            v[i] = a[i];
        }

        // Calculate the minimum values for the current k
        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                // If i-k is out of bounds, use the wrapped index
                v[i] = min(v[i], a[n + i - k]);
            } else {
                // Otherwise, use the normal index
                v[i] = min(v[i], a[i - k]);
            }
            // Accumulate the current answer
            kans += v[i];
        }

        // Update the overall answer with the minimum found so far
        ans = min(ans, kans + k * x);
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

// Function to read an integer from standard input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to return the minimum of two integers
int min(int a, int b) {
    return a < b ? a : b;
}
