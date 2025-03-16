
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// scanner is a wrapper around bufio.Scanner for convenient scanning of input.
typedef struct {
    int *buf;
    int cap;
    int len;
} scanner;

// newScanner initializes a new scanner with default settings.
scanner newScanner(FILE *r) {
    scanner s;
    s.buf = (int*)malloc(sizeof(int) * 100000000);
    s.cap = 100000000;
    s.len = 0;
    return s;
}

// Int reads the next word from the scanner, converts it to an integer, and returns it.
int Int(scanner *s) {
    char c;
    int n = 0;
    while ((c = fgetc(stdin))!= EOF) {
        if (c >= '0' && c <= '9') {
            n = n * 10 + (c - '0');
        } else {
            ungetc(c, stdin);
            break;
        }
    }
    return n;
}

// IntSlice reads a specified number of integers from the scanner and returns them as a slice.
int* IntSlice(scanner *s, int l) {
    if (l == 0) {
        return (int*)malloc(sizeof(int) * 0);
    }
    int *sl = (int*)malloc(sizeof(int) * l);
    for (int i = 0; i < l; i++) {
        sl[i] = Int(s);
    }
    return sl;
}

// iabs returns the absolute value of an integer.
int iabs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

// solve calculates the minimum cost to reach the last stone using dynamic programming.
int solve(int n, int *heights) {
    // Initialize the minimum cost array with a large value.
    int *t = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        t[i] = INT_MAX;
    }

    // The cost to reach the first stone is 0.
    t[0] = 0;

    // Calculate the minimum cost to reach each stone.
    for (int i = 1; i < n; i++) {
        // Cost to reach the current stone from the previous stone.
        if (t[i - 1] + iabs(heights[i] - heights[i - 1]) < t[i]) {
            t[i] = t[i - 1] + iabs(heights[i] - heights[i - 1]);
        }
        // Cost to reach the current stone from two stones back (if possible).
        if (1 < i) {
            if (t[i - 2] + iabs(heights[i] - heights[i - 2]) < t[i]) {
                t[i] = t[i - 2] + iabs(heights[i] - heights[i - 2]);
            }
        }
    }

    // Return the minimum cost to reach the last stone.
    return t[n - 1];
}

// main function reads input, calls the solve function, and prints the result.
int main() {
    FILE *r = stdin;
    scanner sc = newScanner(r);
    int n = Int(&sc);
    int *heights = IntSlice(&sc, n);
    int ans = solve(n, heights);
    printf("%d\n", ans);
    return 0;
}
