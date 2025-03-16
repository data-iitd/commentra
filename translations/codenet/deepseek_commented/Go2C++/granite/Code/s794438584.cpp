
#include <iostream>
#include <cmath>

// max returns the maximum of two integers.
int max(int lhs, int rhs) {
	return std::max(lhs, rhs);
}

int main() {
	int N, M; // N: number of items, M: maximum weight capacity
	std::cin >> N >> M; // Read the number of items and maximum weight capacity
	int values[N], weights[N]; // Arrays to store values and weights of items
	for (int i = 0; i < N; i++) {
		std::cin >> weights[i] >> values[i]; // Read the weight and value of each item
	}
	//std::cout << N << " " << M << std::endl; // Debugging line to print the number of items and maximum weight capacity
	//for (int i = 0; i < N; i++) {
	//	std::cout << values[i] << " " << weights[i] << std::endl; // Debugging line to print the values and weights of items
	//}
	int dp[N+1][M+1]; // Initialize the DP table
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = dp[i-1][j]; // Inherit the maximum value from the previous item
			if (j >= weights[i-1]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1]); // Update the DP table with the current item
			}
		}
	}
	std::cout << dp[N][M] << std::endl; // Print the maximum value that can be achieved
	return 0;
}
