#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate the absolute value.
int iabs(int x) {
    return x < 0 ? -x : x;
}

// Function to solve the problem.
int solve(int n, int heights[]) {
    // Initialize a table t to store the minimum cost to reach each index.
    int *t = (int *)malloc((n + 1) * sizeof(int));
    // Set the initial value of the table to maximum integer.
    for (int i = 0; i <= n; i++) {
        t[i] = INT_MAX;
    }
    // Set the base case, the cost to reach index 0 is 0.
    t[0] = 0;

    // Iterate through the array from index 1 to n-1.
    for (int i = 1; i < n; i++) {
        // Calculate the cost to reach index i from the previous index.
        int prevIndexCost = t[i - 1];
        // Update the cost to reach index i if the difference between heights is beneficial.
        if (heights[i] - heights[i - 1] < 0) {
            prevIndexCost += heights[i] - heights[i - 1];
        } else {
            prevIndexCost -= heights[i] - heights[i - 1];
        }
        // Update the cost to reach index i if the difference between previous index is beneficial.
        if (i - 2 >= 0) {
            int prevPrevIndexCost = t[i - 2];
            if (heights[i] - heights[i - 2] < 0) {
                prevPrevIndexCost += heights[i] - heights[i - 2];
            } else {
                prevPrevIndexCost -= heights[i] - heights[i - 2];
            }
            if (prevIndexCost < t[i]) {
                t[i] = prevIndexCost;
            }
            if (prevPrevIndexCost < t[i]) {
                t[i] = prevPrevIndexCost;
            }
        } else {
            // If the difference between previous index is not valid, only update the cost if the current difference is beneficial.
            if (prevIndexCost < t[i]) {
                t[i] = prevIndexCost;
            }
        }
    }

    // Store the result and free the allocated memory.
    int result = t[n - 1];
    free(t);
    return result;
}

// Main function to read input and call the solve function.
int main() {
    // Read the number of test cases.
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        // Read the number of heights.
        int m;
        scanf("%d", &m);
        int *heights = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &heights[j]);
        }
        // Call the solve function and print the result.
        int ans = solve(m, heights);
        printf("%d\n", ans);
        free(heights);
    }
    return 0;
}

// <END-OF-CODE>
