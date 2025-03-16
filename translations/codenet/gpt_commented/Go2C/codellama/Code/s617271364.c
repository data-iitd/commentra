#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize scanner for input and writer for output
FILE *sc = stdin;
FILE *wtr = stdout;

// Declare global variables
int N, ss, ans, A, B, C;

int main() {
	// Read input values and split them into a slice of strings
	char *X = malloc(1000 * sizeof(char));
	fgets(X, 1000, sc);
	char *Y = malloc(1000 * sizeof(char));
	fgets(Y, 1000, sc);

	// Parse the first four values from the input
	sscanf(X, "%d %d %d %d", &N, &A, &B, &C);
	ss = A + B + C;

	// Initialize arrays for dynamic programming and results
	int *arr = malloc(N * sizeof(int));
	int *dp = malloc(N * sizeof(int));
	ans = 10000;

	// Read N integers from input and populate the array
	for (int i = 0; i < N; i++) {
		fgets(Y, 1000, sc);
		sscanf(Y, "%d", &arr[i]);
	}

	// Perform depth-first search to find the optimal distribution
	dfs(dp, 0, arr);

	// Output the final answer
	fprintf(wtr, "%d\n", ans);

	// Flush the writer to ensure all output is written
	fflush(wtr);

	return 0;
}

// Recursive function to explore all distributions of items
void dfs(int *dp, int times, int *arr) {
	// Base case: if all items have been considered
	if (times >= N) {
		ans = min(ans, calc(dp, arr));
		return;
	}

	// Explore all possible distributions (0 to 3)
	for (int i = 0; i < 4; i++) {
		dp[times] = i;
		dfs(dp, times + 1, arr);
	}
}

// Calculate the cost of the current distribution
int calc(int *dp, int *arr) {
	int cost, AA, BB, CC;
	int memo[4];

	// Count items in each group and calculate their sums
	memset(memo, 0, sizeof(memo));
	for (int i = 0; i < N; i++) {
		memo[dp[i]]++;
		if (dp[i] == 1) {
			AA += arr[i];
		} else if (dp[i] == 2) {
			BB += arr[i];
		} else if (dp[i] == 3) {
			CC += arr[i];
		}
	}

	// Calculate the cost based on the differences from target values
	cost = abs(A - AA) + abs(B - BB) + abs(C - CC);

	// Penalize for missing groups and excess items
	for (int i = 1; i < 4; i++) {
		int a = memo[i];
		if (a < 1) {
			cost += 10000;
		} else {
			cost += (a - 1) * 10;
		}
	}

	return cost;
}

// Helper function to find the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Helper function to find the absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return a * -1;
	}
	return a;
}

// Additional utility functions and types can be defined below

