#include <stdio.h>
#include <math.h>

// max returns the maximum of two integers.
int max(int lhs, int rhs) {
	return (int)fmax(lhs, rhs);
}

int main() {
	int N, M; // N: number of items, M: maximum weight capacity
	scanf("%d %d", &N, &M); // Read the number of items and maximum weight capacity
	int values[N]; // Slice to store values of items
	int weights[N]; // Slice to store weights of items
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &weights[i], &values[i]); // Read the weight and value of each item
	}
	//printf("%d %d\n", N, M); // Debugging line to print the number of items and maximum weight capacity
	//printf("%d %d\n", values, weights); // Debugging line to print the values and weights of items
	int dp[N+1][M+1]; // Initialize the DP table
	for (int i = 0; i < N+1; i++) {
		for (int j = 0; j < M+1; j++) {
			dp[i][j] = dp[i-1][j]; // Inherit the maximum value from the previous item
			if (j >= weights[i-1]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1]); // Update the DP table with the current item
			}
		}
	}
	printf("%d\n", dp[N][M]); // Print the maximum value that can be achieved
	return 0;
}

