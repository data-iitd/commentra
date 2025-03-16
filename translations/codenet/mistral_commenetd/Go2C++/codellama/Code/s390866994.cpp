
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Function to read an integer from standard input
int getInt() {
	int x;
	cin >> x;
	return x;
}

// Function to read a string from standard input
string getString() {
	string x;
	cin >> x;
	return x;
}

// Function to find the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Function to find the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to find the absolute value of an integer
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// Main function
int main() {
	// Initialize variables: N, C, K, and array t
	int N, C, K;
	vector<int> t;

	// Read input: N, C, K
	N = getInt();
	C = getInt();
	K = getInt();

	// Read input: t[i] for i from 0 to N-1
	for (int i = 0; i < N; i++) {
		t.push_back(getInt());
	}

	// Sort array t in ascending order
	sort(t.begin(), t.end());

	// Initialize variables: answer counter ans, counter cnt, and end index end
	int ans = 1;
	int cnt = 1;
	int end = t[0] + K;

	// Iterate through array t from index 1 to N-1
	for (int i = 1; i < N; i++) {
		// If counter cnt is less than C and current element t[i] is within the range [end, end+K], increment counter cnt
		if (cnt < C && t[i] <= end) {
			cnt++;
		} else {
			// Reset counter cnt and update end index end to the current element t[i] plus K
			cnt = 1;
			end = t[i] + K;
			// Increment answer counter ans
			ans++;
		}
	}

	// Print the final answer
	cout << ans << endl;

	return 0;
}

