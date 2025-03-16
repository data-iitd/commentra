
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// iabs returns the absolute value of an integer.
int iabs(int x) {
    if (x < 0) {
        return -x; // Return the negation if x is negative.
    }
    return x; // Return x if it is non-negative.
}

// solve computes the minimum cost to reach the last height using dynamic programming.
int solve(int n, int *heights) {
    int *t = (int *)malloc(sizeof(int) * (n + 1)); // Create a slice to store minimum costs.
    for (int i = 0; i < n + 1; i++) {
        t[i] = 1000000000; // Initialize all costs to a large value.
    }

    t[0] = 0; // The cost to reach the first height is zero.
    for (int i = 1; i < n; i++) {
        // Calculate the cost to reach the current height from the previous height.
        if (t[i - 1] + iabs(heights[i] - heights[i - 1]) < t[i]) {
            t[i] = t[i - 1] + iabs(heights[i] - heights[i - 1]); // Update the cost if it's lower.
        }
        // Calculate the cost to reach the current height from two heights back.
        if (1 < i) {
            if (t[i - 2] + iabs(heights[i] - heights[i - 2]) < t[i]) {
                t[i] = t[i - 2] + iabs(heights[i] - heights[i - 2]); // Update the cost if it's lower.
            }
        }
    }

    int ans = t[n - 1]; // Return the minimum cost to reach the last height.
    free(t); // Free the memory allocated for the slice.
    return ans;
}

int main() {
    int n; // Read the number of heights.
    scanf("%d", &n);
    int *heights = (int *)malloc(sizeof(int) * n); // Read the heights into a slice.
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    int ans = solve(n, heights); // Solve for the minimum cost.
    printf("%d\n", ans); // Print the result.
    free(heights); // Free the memory allocated for the slice.
    return 0;
}

