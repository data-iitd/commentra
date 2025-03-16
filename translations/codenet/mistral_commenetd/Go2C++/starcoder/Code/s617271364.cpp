
#include <bits/stdc++.h>

using namespace std;

// Global variables
int N, ss, ans, A, B, C;

// sort function is used to sort an array in ascending order
// type IntSlice []int
// func (a IntSlice) Len() int           { return len(a) }
// func (a IntSlice) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
// func (a IntSlice) Less(i, j int) bool { return a[i] < a[j] }

int main() {
	// Read the first line which contains the number of tests and the number of elements in the array
	cin >> N >> A >> B >> C;

	// Initialize the global variables
	ss = A + B + C;

	// Initialize the array and the dp array
	vector<int> arr(N);
	vector<int> dp(N);

	// Initialize the answer variable
	ans = 10000;

	// Read the next N lines which contain the elements of the array
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// Call the dfs function to find the minimum cost
	dfs(dp, 0, arr);

	// Print the answer
	cout << ans << endl;

	return 0;
}

// dfs function is used for depth-first search
void dfs(vector<int> &dp, int times, vector<int> &arr) {
	// Base case: if the number of elements processed is equal to N, calculate the cost and update the answer if necessary
	if (times >= N) {
		ans = min(ans, calc(dp, arr));
		return;
	}

	// Recursive case: try all possible values for the current element
	for (int i = 0; i < 4; i++) {
		dp[times] = i;
		dfs(dp, times + 1, arr);
	}
}

// calc function is used to calculate the cost
int calc(vector<int> &dp, vector<int> &arr) {
	// Initialize the cost and the variables to store the sum of elements with each value in dp
	int cost = 0, AA = 0, BB = 0, CC = 0;

	// Initialize the memo array to store the number of elements with each value in dp
	vector<int> memo(4);

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
	for (int i = 1; i < 4; i++) {
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

// Helper functions
string nextLine() {
	string s;
	getline(cin, s);
	return s;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
int com(int a, int b) {
	if (a > b) {
		return 0;
	}
	return 0; //abs(a - b)
}
int abs(int a) {
	if (a < 0) {
		return a * -1;
	}
	return a;
}
int sum(vector<int> a) {
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i];
	}
	return sum;
}

