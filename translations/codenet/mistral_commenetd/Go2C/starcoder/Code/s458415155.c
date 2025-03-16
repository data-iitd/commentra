
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom scanner type for reading input efficiently.
typedef struct {
	char *s;
	int len;
	int pos;
} scanner;

// NewScanner function creates a new instance of the scanner type.
scanner *newScanner(char *s) {
	scanner *sc = malloc(sizeof(scanner));
	sc->s = s;
	sc->len = strlen(s);
	sc->pos = 0;
	return sc;
}

// Define helper functions for converting scanner output to int and int slice.
int parseInt(scanner *sc) {
	int n = 0;
	while (sc->pos < sc->len && s[sc->pos]!='') {
		n = n * 10 + (s[sc->pos] - '0');
		sc->pos++;
	}
	sc->pos++;
	return n;
}

int *parseIntSlice(scanner *sc, int l) {
	int *sl = malloc(sizeof(int) * l);
	for (int i = 0; i < l; i++) {
		sl[i] = parseInt(sc);
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
	int *t = malloc(sizeof(int) * (n + 1));
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
		int heightsDiff = heights[i] - heights[i - 1];
		if (heightsDiff < 0) {
			prevIndexCost += heightsDiff;
		} else {
			prevIndexCost -= heightsDiff;
		}
		// Update the cost to reach index i if the difference between previous index is beneficial.
		int prevIndex = i - 2;
		if (prevIndex >= 0) {
			int prevPrevIndexCost = t[prevIndex];
			int heightsDiff = heights[i] - heights[prevIndex];
			if (heightsDiff < 0) {
				prevPrevIndexCost += heightsDiff;
			} else {
				prevPrevIndexCost -= heightsDiff;
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
	// Read the number of test cases and iterate through each test case.
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		// Read the number of heights and initialize an array to store them.
		int *heights = parseIntSlice(sc, n);
		// Call the solve function and print the result.
		printf("%d\n", solve(n, heights));
	}
	return 0;
}

// The following comment can be added at the end of the code.

