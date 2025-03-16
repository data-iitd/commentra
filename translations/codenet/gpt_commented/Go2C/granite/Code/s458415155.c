
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a scanner structure to provide convenient methods for reading input.
typedef struct {
    int *buf;
    int len;
    int cap;
} Scanner;

// Initialize a new scanner with a specified input reader.
Scanner *newScanner(FILE *r) {
    Scanner *s = (Scanner *)malloc(sizeof(Scanner));
    s->buf = (int *)malloc(sizeof(int) * 100000000);
    s->len = 0;
    s->cap = 100000000;
    return s;
}

// Free the memory allocated for the scanner.
void freeScanner(Scanner *s) {
    free(s->buf);
    free(s);
}

// Read the next integer from the input.
int nextInt(Scanner *s) {
    if (s->len >= s->cap) {
        // Reallocate the buffer if it's full.
        s->buf = (int *)realloc(s->buf, sizeof(int) * (s->cap *= 2));
    }
    fscanf(stdin, "%d", s->buf + s->len);
    return s->buf[s->len++];
}

// Read a slice of integers from the input with the specified length.
int *nextIntSlice(Scanner *s, int l) {
    int *sl = (int *)malloc(sizeof(int) * l);
    for (int i = 0; i < l; i++) {
        sl[i] = nextInt(s);
    }
    return sl;
}

// Calculate the absolute value of an integer.
int iabs(int x) {
    return x < 0? -x : x;
}

// Compute the minimum cost to reach the last height using dynamic programming.
int solve(int n, int *heights) {
    int *t = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        t[i] = INT_MAX; // Initialize all costs to a large value.
    }
    t[0] = 0; // The cost to reach the first height is zero.
    for (int i = 1; i < n; i++) {
        // Calculate the cost to reach the current height from the previous height.
        int cost = t[i - 1] + iabs(heights[i] - heights[i - 1]);
        if (cost < t[i]) {
            t[i] = cost; // Update the cost if it's lower.
        }
        // Calculate the cost to reach the current height from two heights back.
        if (i > 1) {
            cost = t[i - 2] + iabs(heights[i] - heights[i - 2]);
            if (cost < t[i]) {
                t[i] = cost; // Update the cost if it's lower.
            }
        }
    }
    int ans = t[n - 1]; // Return the minimum cost to reach the last height.
    free(t);
    return ans;
}

int main() {
    Scanner *sc = newScanner(stdin); // Initialize the scanner for standard input.
    int n = nextInt(sc); // Read the number of heights.
    int *heights = nextIntSlice(sc, n); // Read the heights into a slice.
    int ans = solve(n, heights); // Solve for the minimum cost.
    printf("%d\n", ans); // Print the result.
    freeScanner(sc);
    free(heights);
    return 0;
}
