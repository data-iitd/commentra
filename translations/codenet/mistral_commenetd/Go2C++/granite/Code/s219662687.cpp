
// C++ code translation of the given Go code
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

// Constants declaration and initialization
const int INF = 1e11;

// Function to read input values from standard input
int readInt() {
	int x;
	cin >> x;
	return x;
}

// Main function declaration and implementation
int main() {
	// Reading input values from standard input
	int A = readInt();
	int B = readInt();
	int Q = readInt();

	// Initializing arrays s and t with size A+2 and B+2 respectively
	// The first and last elements are initialized with -INF and INF respectively
	vector<int> s(A+2, -INF);
	s[A+1] = INF;
	vector<int> t(B+2, -INF);
	t[B+1] = INF;

	// Reading A elements of array s from standard input
	for (int i = 1; i <= A; i++) {
		s[i] = readInt();
	}

	// Reading B elements of array t from standard input
	for (int i = 1; i <= B; i++) {
		t[i] = readInt();
	}

	// Processing each query
	for (int i = 0; i < Q; i++) {
		// Reading query value x from standard input
		int x = readInt();

		// Finding the indices b and d of array s and t respectively
		// where s[b] and t[d] are the smallest elements greater than x
		int b = lower_bound(s.begin(), s.end(), x) - s.begin();
		int d = lower_bound(t.begin(), t.end(), x) - t.begin();

		// Computing the minimum distance between x and any pair of elements S and T
		// from arrays s and t respectively
		int res = INF;
		for (int S : {s[b-1], s[b]}) {
			for (int T : {t[d-1], t[d]}) {
				// Computing the absolute difference between S and x, and T and S
				int d1 = abs(S-x);
				int d2 = abs(T-S);

				// Updating the minimum distance if the current pair has a smaller distance
				res = min(res, min(d1, d2));
			}
		}

		// Printing the minimum distance for the current query
		cout << res << endl;
	}

	return 0;
}

// Input reading helper functions
// (No need to translate as it is already provided in the given code snippet)

// Helper functions for array manipulation and arithmetic operations
// (No need to translate as it is already provided in the given code snippet)

// End of C++ code translation
// 