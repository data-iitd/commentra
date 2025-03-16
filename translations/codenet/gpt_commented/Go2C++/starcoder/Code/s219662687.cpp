#include <bits/stdc++.h>

using namespace std;

// Define a large constant for infinity
const int INF = 1e11;

// Function to read the next integer from input
int nextInt() {
	int x;
	cin >> x;
	return x;
}

// Function to read the next float from input
double nextFloat() {
	double x;
	cin >> x;
	return x;
}

// Function to read the next string from input
string nextString() {
	string x;
	cin >> x;
	return x;
}

// Utility functions. ----------

// Function to calculate the absolute value
int abs(int x) {
	return x < 0? -x : x;
}

// Function to find the minimum of two integers
int min(int x, int y) {
	return x < y? x : y;
}

// Function to find the maximum of two integers
int max(int x, int y) {
	return x > y? x : y;
}

// ---------- Utility functions.

int main() {
	// Read the number of elements in the first array A and initialize it
	int A = nextInt();
	// Read the number of elements in the second array B
	int B = nextInt();
	// Read the number of queries Q
	int Q = nextInt();

	// Initialize the first array with boundary values
	vector<int> s(A+2, INF);
	s[0] = -INF;
	s[A+1] = INF;
	// Populate the first array with input values
	for (int i = 1; i <= A; i++) {
		s[i] = nextInt();
	}

	// Initialize the second array with boundary values
	vector<int> t(B+2, INF);
	t[0] = -INF;
	t[B+1] = INF;
	// Populate the second array with input values
	for (int i = 1; i <= B; i++) {
		t[i] = nextInt();
	}

	// Process each query
	for (int i = 0; i < Q; i++) {
		// Read the query value x
		int x = nextInt();
		// Find the position in the first array where x would fit
		int b = lower_bound(s.begin(), s.end(), x) - s.begin();
		// Find the position in the second array where x would fit
		int d = lower_bound(t.begin(), t.end(), x) - t.begin();
		// Initialize the result with infinity
		int res = INF;

		// Check the closest values in the first array
		for (int S : {s[b-1], s[b]}) {
			// Check the closest values in the second array
			for (int T : {t[d-1], t[d]}) {
				// Calculate the distances for both possible paths
				int d1 = abs(S-x) + abs(T-S);
				int d2 = abs(T-x) + abs(S-T);
				// Update the result with the minimum distance found
				res = min(res, min(d1, d2));
			}
		}

		// Output the result for the current query
		cout << res << endl;
	}
}

