// Package main is the entry point of the program
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// main function is the entry point of the program
int main() {
	// Read the number of test cases N from standard input
	int N;
	cin >> N;

	// Read an array h of N integers from standard input
	vector<int> h(N);
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}

	// Initialize a dp array of size N with zeros
	vector<int> dp(N, 0);

	// Set the first element of dp to the absolute difference between the first and second elements of h
	dp[1] = abs(h[0] - h[1]);

	// Iterate over the array h from the second element to the last
	for (int i = 2; i < N; i++) {
		// Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
	}

	// Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
	cout << dp[N - 1] << endl;

	return 0;
}

