
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a custom scanner type for reading input efficiently.
typedef struct {
    char *buf;
    int buf_size;
    int buf_pos;
    int buf_len;
} scanner;

// NewScanner function creates a new instance of the scanner type.
scanner *newScanner(FILE *r) {
    scanner *s = (scanner *)malloc(sizeof(scanner));
    s->buf_size = 100000000;
    s->buf = (char *)malloc(s->buf_size * sizeof(char));
    s->buf_pos = 0;
    s->buf_len = 0;
    return s;
}

// Define helper functions for converting scanner output to int and int slice.
int scanner_int(scanner *s) {
    int n;
    sscanf(s->buf + s->buf_pos, "%d", &n);
    s->buf_pos += strlen(s->buf + s->buf_pos);
    return n;
}

int *scanner_int_slice(scanner *s, int l) {
    if (l == 0) {
        return NULL;
    }
    int *sl = (int *)malloc(l * sizeof(int));
    for (int i = 0; i < l; i++) {
        sl[i] = scanner_int(s);
    }
    return sl;
}

// Define a helper function for calculating absolute value.
int iabs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

// Define the main function to solve the problem.
int solve(int n, int *heights) {
    // Initialize a table t to store the minimum cost to reach each index.
    int *t = (int *)malloc((n + 1) * sizeof(int));
    // Set the initial value of the table to maximum integer.
    for (int i = 0; i < n + 1; i++) {
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

    // Return the minimum cost to reach the last index.
    return t[n - 1];
}

// Define the main function to read input and call the solve function.
int main() {
    // Initialize a scanner to read input from standard input.
    scanner *sc = newScanner(stdin);
    // Read the number of test cases and iterate through each test case.
    int n = scanner_int(sc);
    for (int i = 0; i < n; i++) {
        // Read the number of heights and initialize an array to store them.
        int *heights = scanner_int_slice(sc, n);
        // Call the solve function and print the result.
        int ans = solve(n, heights);
        printf("%d\n", ans);
    }
    return 0;
}

// The following comment can be added at the end of the code.


