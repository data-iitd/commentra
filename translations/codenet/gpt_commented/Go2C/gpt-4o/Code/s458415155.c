#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Function to read an integer from input.
int readInt() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read an array of integers from input.
int* readIntArray(int length) {
    int* array = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        array[i] = readInt();
    }
    return array;
}

// Function to compute the absolute value of an integer.
int iabs(int x) {
    return x < 0 ? -x : x;
}

// Function to solve the problem using dynamic programming.
int solve(int n, int* heights) {
<<<<<<< HEAD
    int* t = (int*)malloc((n + 1) * sizeof(int)); // Array to store minimum costs.
=======
    int* t = (int*)malloc((n + 1) * sizeof(int));
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i <= n; i++) {
        t[i] = INT_MAX; // Initialize all costs to a large value.
    }

    t[0] = 0; // The cost to reach the first height is zero.
    for (int i = 1; i < n; i++) {
        // Calculate the cost to reach the current height from the previous height.
        int v = t[i - 1] + iabs(heights[i] - heights[i - 1]);
        if (v < t[i]) {
            t[i] = v; // Update the cost if it's lower.
        }
        // Calculate the cost to reach the current height from two heights back.
        if (i > 1) {
            v = t[i - 2] + iabs(heights[i] - heights[i - 2]);
            if (v < t[i]) {
                t[i] = v; // Update the cost if it's lower.
            }
        }
    }

    int result = t[n - 1]; // Get the minimum cost to reach the last height.
    free(t); // Free the allocated memory for costs.
    return result;
}

// Main function to execute the program.
int main() {
    int n = readInt(); // Read the number of heights.
    int* heights = readIntArray(n); // Read the heights into an array.
    int ans = solve(n, heights); // Solve for the minimum cost.
    printf("%d\n", ans); // Print the result.
    free(heights); // Free the allocated memory for heights.
    return 0;
}

// <END-OF-CODE>
