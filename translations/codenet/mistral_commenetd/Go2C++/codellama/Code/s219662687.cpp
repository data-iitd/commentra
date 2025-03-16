// Package declaration and importing necessary headers
#include <bits/stdc++.h>

// Main function declaration and initialization of constants
int main() {
	const int INF = 1e11; // Large constant value for initializing arrays

	// Reading input values from standard input
	int A = nextInt();
	int B = nextInt();
	int Q = nextInt();

	// Initializing arrays s and t with size A+2 and B+2 respectively
	// The first and last elements are initialized with -INF and INF respectively
	int s[A+2];
	s[0], s[A+1] = -INF, INF;

	// Reading A elements of array s from standard input
	for (int i = 1; i <= A; i++) {
		s[i] = nextInt();
	}

	// Initializing array t with size B+2
	// The first and last elements are initialized with -INF and INF respectively
	int t[B+2];
	t[0], t[B+1] = -INF, INF;

	// Reading B elements of array t from standard input
	for (int i = 1; i <= B; i++) {
		t[i] = nextInt();
	}

	// Processing each query
	for (int i = 0; i < Q; i++) {
		// Reading query value x from standard input
		int x = nextInt();

		// Finding the indices b and d of array s and t respectively
		// where s[b] and t[d] are the smallest elements greater than x
		int b = lower_bound(s, s+A+2, x) - s;
		int d = lower_bound(t, t+B+2, x) - t;

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
int nextInt() {
	int x;
	cin >> x;
	return x;
}

float nextFloat() {
	float x;
	cin >> x;
	return x;
}

string nextString() {
	string x;
	cin >> x;
	return x;
}

// Helper functions for array manipulation and arithmetic operations
int abs(int x) {
	return x < 0 ? -x : x;
}

int min(int x, int y) {
	return x < y ? x : y;
}

int max(int x, int y) {
	return x > y ? x : y;
}

