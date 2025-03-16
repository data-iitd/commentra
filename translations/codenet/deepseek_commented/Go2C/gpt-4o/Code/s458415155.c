#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Function to calculate the absolute value of an integer.
int iabs(int x) {
    return x < 0 ? -x : x;
}

// Function to calculate the minimum cost to reach the last stone using dynamic programming.
int solve(int n, int heights[]) {
    // Initialize the minimum cost array with a large value.
    int *t = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        t[i] = INT_MAX;
    }

    // The cost to reach the first stone is 0.
    t[0] = 0;

    // Calculate the minimum cost to reach each stone.
    for (int i = 1; i < n; i++) {
        // Cost to reach the current stone from the previous stone.
        int v = t[i - 1] + iabs(heights[i] - heights[i - 1]);
        if (v < t[i]) {
            t[i] = v;
        }
        // Cost to reach the current stone from two stones back (if possible).
        if (i > 1) {
            v = t[i - 2] + iabs(heights[i] - heights[i - 2]);
            if (v < t[i]) {
                t[i] = v;
            }
        }
    }

    // Store the result for the last stone.
    int result = t[n - 1];
    free(t); // Free the allocated memory.
    return result;
}

// Main function reads input, calls the solve function, and prints the result.
int main() {
    int n;
    scanf("%d", &n);
    int *heights = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    int ans = solve(n, heights);
    printf("%d\n", ans);
    free(heights); // Free the allocated memory.
    return 0;
}

// <END-OF-CODE>
