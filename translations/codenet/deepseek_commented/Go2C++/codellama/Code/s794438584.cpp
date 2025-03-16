
#include <iostream>
#include <cmath>

using namespace std;

// max returns the maximum of two integers.
int max(int lhs, int rhs) {
	return int(max(lhs, rhs));
}

int main() {
	int N, M; // N: number of items, M: maximum weight capacity
	cin >> N >> M; // Read the number of items and maximum weight capacity
	int values[N]; // Array to store values of items
	int weights[N]; // Array to store weights of items
	for (int i = 0; i < N; i++) {
		cin >> weights[i] >> values[i]; // Read the weight and value of each item
	}
	//cout << N << " " << M << endl; // Debugging line to print the number of items and maximum weight capacity
	//cout << values << " " << weights << endl; // Debugging line to print the values and weights of items
	int dp[N+1][M+1]; // Initialize the DP table
	for (int i = 0; i < N+1; i++) {
		for (int j = 0; j < M+1; j++) {
			dp[i][j] = dp[i-1][j]; // Inherit the maximum value from the previous item
			if (j >= weights[i-1]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1]); // Update the DP table with the current item
			}
		}
	}
	cout << dp[N][M] << endl; // Print the maximum value that can be achieved
	return 0;
}

