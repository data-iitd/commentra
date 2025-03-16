
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// iabs returns the absolute value of an integer.
int iabs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

// solve calculates the minimum cost to reach the last stone using dynamic programming.
int solve(int n, int heights[]) {
	// Initialize the minimum cost array with a large value.
	int t[n+1];
	for (int i = 0; i < n+1; i++) {
		t[i] = 2147483647;
	}

	// The cost to reach the first stone is 0.
	t[0] = 0;

	// Calculate the minimum cost to reach each stone.
	for (int i = 1; i < n; i++) {
		// Cost to reach the current stone from the previous stone.
		if (t[i-1] + iabs(heights[i] - heights[i-1]) < t[i]) {
			t[i] = t[i-1] + iabs(heights[i] - heights[i-1]);
		}
		// Cost to reach the current stone from two stones back (if possible).
		if (i > 1) {
			if (t[i-2] + iabs(heights[i] - heights[i-2]) < t[i]) {
				t[i] = t[i-2] + iabs(heights[i] - heights[i-2]);
			}
		}
	}

	// Return the minimum cost to reach the last stone.
	return t[n-1];
}

// main function reads input, calls the solve function, and prints the result.
int main() {
	int n;
	scanf("%d", &n);
	int heights[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &heights[i]);
	}
	int ans = solve(n, heights);
	printf("%d\n", ans);
	return 0;
}

