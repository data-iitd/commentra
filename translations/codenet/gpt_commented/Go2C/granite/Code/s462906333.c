
#include <stdio.h>
#include <stdlib.h>

// Define a large constant for infinity
#define inf 100000000

// ---------------------------------------------------------
int main() {
    // Set log flags to show the file name and line number
    setbuf(stdout, NULL);
    setvbuf(stderr, NULL, _IONBF, 0);

    // Initialize a new scanner for input
    FILE *fp = stdin;
    char buf[10000];
    fgets(buf, 10000, fp);
    int n = atoi(buf);
    fgets(buf, 10000, fp);
    int x = atoi(buf);

    // Create a slice to hold the input integers
    int a[n];
    for (int i = 0; i < n; i++) {
        fgets(buf, 10000, fp);
        a[i] = atoi(buf);
    }

    // Create a copy of the slice a for manipulation
    int v[n];
    for (int i = 0; i < n; i++) {
        v[i] = a[i];
    }

    // Initialize the answer to infinity
    int ans = inf;

    // Iterate over each possible k value
    for (int k = 0; k < n; k++) {
        int kans = 0; // Initialize the current answer for this k

        // Calculate the minimum values for the current k
        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                // If i-k is out of bounds, use the wrapped index
                v[i] = (v[i] < a[n + i - k])? v[i] : a[n + i - k];
            } else {
                // Otherwise, use the normal index
                v[i] = (v[i] < a[i - k])? v[i] : a[i - k];
            }
            // Accumulate the current answer
            kans += v[i];
        }

        // Update the overall answer with the minimum found so far
        ans = (ans < kans + k * x)? ans : kans + k * x;
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

// ---------------------------------------------------------
