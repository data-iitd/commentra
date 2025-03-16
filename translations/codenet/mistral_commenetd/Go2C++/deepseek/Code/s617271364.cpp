#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Global variables
int N, A, B, C;

// Helper functions
string nextLine() {
	string line;
	getline(cin, line);
	return line;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int abs(int a) {
	return a < 0 ? -a : a;
}

int calc(const vector<int>& dp, const vector<int>& arr) {
	// Initialize the cost and the variables to store the sum of elements with each value in dp
	int cost = 0;
	int AA = 0, BB = 0, CC = 0;

	// Initialize the memo array to store the number of elements with each value in dp
	vector<int> memo(4, 0);

	// Iterate through the dp array and update the variables
	for (int i = 0; i < dp.size(); i++) {
		// Update the variables based on the current value in dp
		int a = dp[i];
		memo[a]++;
		if (a == 1) {
			AA += arr[i];
		} else if (a == 2) {
			BB += arr[i];
		} else if (a == 3) {
			CC += arr[i];
		}
	}

	// Calculate the cost based on the variables
	cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

	// Update the cost based on the number of elements with each value in dp
	for (int i = 1; i <= 3; i++) {
		int a = memo[i];
		if (a < 1) {
			cost += 10000;
		} else {
			cost += (a - 1) * 10;
		}
	}

	// Return the cost
	return cost;
}

void dfs(vector<int>& dp, int times, const vector<int>& arr) {
	// Base case: if the number of elements processed is equal to N, calculate the cost and update the answer if necessary
	if (times >= N) {
		int ans = calc(dp, arr);
		// Update the global answer variable
		if (ans < ::ans) {
			::ans = ans;
		}
		return;
	}

	// Recursive case: try all possible values for the current element
	for (int i = 0; i < 4; i++) {
		dp[times] = i;
		dfs(dp, times + 1, arr);
	}
}

int main() {
	// Read the first line which contains the number of tests and the number of elements in the array
	string line = nextLine();
	istringstream iss(line);
	vector<string> X;
	string x;
	while (iss >> x) {
		X.push_back(x);
	}

	// Initialize the global variables
	N = stoi(X[0]);
	A = stoi(X[1]);
	B = stoi(X[2]);
	C = stoi(X[3]);

	// Initialize the array and the dp array
	vector<int> arr(N);
	vector<int> dp(N);

	// Initialize the answer variable
	::ans = 10000;

	// Read the next N lines which contain the elements of the array
	for (int i = 0; i < N; i++) {
		line = nextLine();
		istringstream iss(line);
		vector<string> Y;
		while (iss >> x) {
			Y.push_back(x);
		}

		// Read an element of the array
		arr[i] = stoi(Y[0]);
	}

	// Call the dfs function to find the minimum cost
	dfs(dp, 0, arr);

	// Print the answer
	cout << ::ans << endl;

	return 0;
}
