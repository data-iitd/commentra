
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define a large constant for infinity
#define INF 10000000000

// Function to calculate the absolute value
int abs(int x) {
	return (int)fabs(x);
}

// Function to find the minimum of two integers
int min(int x, int y) {
	return (int)fmin(x, y);
}

// Function to find the maximum of two integers
int max(int x, int y) {
	return (int)fmax(x, y);
}

int main() {
	// Read the number of elements in the first array A and initialize it
	int A = 0;
	scanf("%d", &A);
	int s[A+2];
	s[0] = -INF;
	s[A+1] = INF;
	// Populate the first array with input values
	for (int i = 1; i <= A; i++) {
		scanf("%d", &s[i]);
	}

	// Read the number of elements in the second array B
	int B = 0;
	scanf("%d", &B);
	int t[B+2];
	t[0] = -INF;
	t[B+1] = INF;
	// Populate the second array with input values
	for (int i = 1; i <= B; i++) {
		scanf("%d", &t[i]);
	}

	// Read the number of queries Q
	int Q = 0;
	scanf("%d", &Q);

	// Process each query
	for (int i = 0; i < Q; i++) {
		// Read the query value x
		int x = 0;
		scanf("%d", &x);
		// Find the position in the first array where x would fit
		int b = 0, d = 0;
		for (int j = 0; j < A; j++) {
			if (s[j] <= x && x <= s[j+1]) {
				b = j;
				break;
			}
		}
		for (int j = 0; j < B; j++) {
			if (t[j] <= x && x <= t[j+1]) {
				d = j;
				break;
			}
		}
		// Initialize the result with infinity
		int res = INF;

		// Check the closest values in the first array
		for (int j = -1; j <= 1; j++) {
			// Check the closest values in the second array
			for (int k = -1; k <= 1; k++) {
				// Calculate the distances for both possible paths
				int d1 = abs(s[b+j]-x)+abs(t[d+k]-s[b+j]);
				int d2 = abs(t[d+k]-x)+abs(s[b+j]-t[d+k]);
				// Update the result with the minimum distance found
				res = min(res, min(d1, d2));
			}
		}

		// Output the result for the current query
		printf("%d\n", res);
	}

	return 0;
}

