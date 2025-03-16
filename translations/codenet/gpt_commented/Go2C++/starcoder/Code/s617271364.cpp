#include <bits/stdc++.h>

using namespace std;

// Declare global variables
int N, ss, ans, A, B, C;

int main() {
	// Read input values and split them into a vector of strings
	vector<string> X;
	string s;
	getline(cin, s);
	istringstream iss(s);
	while (getline(iss, s,'')) {
		X.push_back(s);
	}

	// Parse the first four values from the input
	N = stoi(X[0]); // Number of elements
	A = stoi(X[1]); // Target value A
	B = stoi(X[2]); // Target value B
	C = stoi(X[3]); // Target value C

	// Initialize arrays for dynamic programming and results
	vector<int> arr(N); // Array to hold input values
	vector<int> dp(N);  // DP array to store current state
	ans = 10000;        // Initialize answer with a large value
	ss = A + B + C;     // Sum of target values

	// Read N integers from input and populate the array
	for (int i = 0; i < N; i++) {
		getline(cin, s);
		arr[i] = stoi(s); // Store the integer in the array
	}

	// Perform depth-first search to find the optimal distribution
	dfs(dp, 0, arr);

	// Output the final answer
	cout << ans << endl;

	return 0;
}

// Recursive function to explore all distributions of items
void dfs(vector<int>& dp, int times, vector<int>& arr) {
	// Base case: if all items have been considered
	if (times >= N) {
		ans = min(ans, calc(dp, arr)); // Calculate cost and update answer
		return;
	}

	// Explore all possible distributions (0 to 3)
	for (int i = 0; i < 4; i++) {
		dp[times] = i; // Assign current item to one of the four groups
		dfs(dp, times + 1, arr); // Recur for the next item
	}
}

// Calculate the cost of the current distribution
int calc(vector<int>& dp, vector<int>& arr) {
	int cost = 0, AA = 0, BB = 0, CC = 0; // Initialize cost and group sums

	// Count items in each group and calculate their sums
	vector<int> memo(4);
	for (int i = 0; i < dp.size(); i++) {
		memo[dp[i]]++; // Count items in each group
		if (dp[i] == 1) {
			AA += arr[i]; // Sum for group A
		} else if (dp[i] == 2) {
			BB += arr[i]; // Sum for group B
		} else if (dp[i] == 3) {
			CC += arr[i]; // Sum for group C
		}
	}

	// Calculate the cost based on the differences from target values
	cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

	// Penalize for missing groups and excess items
	for (int i = 1; i < 4; i++) {
		int a = memo[i];
		if (a < 1) {
			cost += 10000; // High penalty for missing group
		} else {
			cost += (a - 1) * 10; // Penalty for excess items
		}
	}

	return cost; // Return the calculated cost
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

