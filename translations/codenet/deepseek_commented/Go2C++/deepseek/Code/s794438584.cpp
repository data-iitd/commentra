#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// max returns the maximum of two integers.
int max(int lhs, int rhs) {
	return std::max(lhs, rhs);
}

int main() {
	int N, M; // N: number of items, M: maximum weight capacity
	cin >> N >> M; // Read the number of items and maximum weight capacity
	vector<int> values(N); // Vector to store values of items
	vector<int> weights(N); // Vector to store weights of items
	for (int i = 0; i < N; i++) {
		cin >> weights[i] >> values[i]; // Read the weight and value of each item
	}
	//cout << N << " " << M << endl; // Debugging line to print the number of items and maximum weight capacity
	//for (int i = 0; i < N; i++) {
	//	cout << values[i] << " " << weights[i] << endl; // Debugging line to print the values and weights of items
	//}
	vector<vector<int>> dp(N+1, vector<int>(M+1, 0)); // Initialize the DP table
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = dp[i-1][j]; // Inherit the maximum value from the previous item
			if (j >= weights[i-1]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]] + values[i-1]); // Update the DP table with the current item
			}
		}
	}
	cout << dp[N][M] << endl; // Print the maximum value that can be achieved
}
