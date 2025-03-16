#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate the absolute value of an integer
int abs(int x) {
    return x < 0 ? -x : x;
}

// Function to solve the problem using dynamic programming
int solve(int n, int* heights) {
    // Initialize the minimum cost array with a large value
    int* t = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        t[i] = INT_MAX;
    }

    // The cost to reach the first stone is 0
    t[0] = 0;

    // Calculate the minimum cost to reach each stone
    for (int i = 1; i < n; i++) {
        // Cost to reach the current stone from the previous stone
        if (t[i - 1] + abs(heights[i] - heights[i - 1]) < t[i]) {
            t[i] = t[i - 1] + abs(heights[i] - heights[i - 1]);
        }
        // Cost to reach the current stone from two stones back (if possible)
        if (i > 1 && t[i - 2] + abs(heights[i] - heights[i - 2]) < t[i]) {
            t[i] = t[i - 2] + abs(heights[i] - heights[i - 2]);
        }
    }

    // Return the minimum cost to reach the last stone
    int result = t[n - 1];
    free(t);
    return result;
}

// Main function to read input, call the solve function, and print the result
int main() {
    int n;
    scanf("%d", &n);
    int* heights = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    int ans = solve(n, heights);
    printf("%d\n", ans);
    free(heights);
    return 0;
}

