
#include <bits/stdc++.h>

using namespace std;

// Function to calculate the absolute value
int abs(int x) {
	return abs(x);
}

// Function to find the minimum of two integers
int min(int x, int y) {
	return min(x, y);
}

// Function to find the maximum of two integers
int max(int x, int y) {
	return max(x, y);
}

int main() {
	// Define a large constant for infinity
	const int INF = 1e11;

	// Read the number of elements in the first array A and initialize it
	int A = 0;
	cin >> A;
	vector<int> s(A+2, 0);
	s[0] = -INF;
	s[A+1] = INF;
	// Populate the first array with input values
	for (int i = 1; i <= A; i++) {
		cin >> s[i];
	}

	// Read the number of elements in the second array B
	int B = 0;
	cin >> B;
	vector<int> t(B+2, 0);
	t[0] = -INF;
	t[B+1] = INF;
	// Populate the second array with input values
	for (int i = 1; i <= B; i++) {
		cin >> t[i];
	}

	// Read the number of queries Q
	int Q = 0;
	cin >> Q;

	// Process each query
	for (int i = 0; i < Q; i++) {
		// Read the query value x
		int x = 0;
		cin >> x;
		// Find the position in the first array where x would fit
		int b = lower_bound(s.begin(), s.end(), x) - s.begin();
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

	return 0;
}

