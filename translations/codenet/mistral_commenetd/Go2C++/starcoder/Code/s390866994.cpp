
#include <bits/stdc++.h>

using namespace std;

// Function to read an integer from standard input
int getInt() {
	int x;
	cin >> x;
	return x;
}

// Function to read a string from standard input
string getString() {
	string s;
	cin >> s;
	return s;
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
	// Initialize variables: N, C, K, t, ans, cnt, and end
	int N, C, K, t, ans, cnt, end;

	// Read input: N, C, K
	N = getInt();
	C = getInt();
	K = getInt();

	// Initialize array t of size N
	t = new int[N];

	// Read input: t[i] for i from 0 to N-1
	for (int i = 0; i < N; i++) {
		t[i] = getInt();
	}

	// Sort array t in ascending order
	sort(t, t + N);

	// Initialize variables: ans, cnt, and end
	ans = 1;
	cnt = 1;
	end = t[0] + K;

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

	// Delete array t
	delete[] t;

	return 0;
}

