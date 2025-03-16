#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// max function returns the maximum of two integers.
int max(int lhs, int rhs) {
	return std::max(lhs, rhs);
}

int main() {
	// Declare variables for the number of items (N) and the maximum weight (M).
	int N, M;

	// Read the number of items and the maximum weight from standard input.
	cin >> N >> M;

	// Initialize vectors to hold the weights and values of the items.
	vector<int> values(N);
	vector<int> weights(N);

	// Read the weights and values of each item from standard input.
	for (int i = 0; i < N; i++) {
		cin >> weights[i] >> values[i];
	}

	// Initialize a 2D vector for dynamic programming table.
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

	// Fill the dynamic programming table.
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			// If the current item is not included, carry forward the previous value.
			dp[i][j] = dp[i - 1][j];

			// If the current item's weight is less than or equal to the current capacity.
			if (j >= weights[i - 1]) {
				// Calculate the maximum value by including the current item.
				dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
			}
		}
	}

	// Output the maximum value that can be obtained with the given weight limit.
	cout << dp[N][M] << endl;

