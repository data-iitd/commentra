#include <bits/stdc++.h>

using namespace std;

const int magic = 1000000007;

int N;
int p[200000];

// find function checks if a given number n is present in the p slice
int find(int n) {
	for (int i = 0; i < N; i++) {
		if (n == p[i]) {
			return 0;
		}
	}
	return 1;
}

// solve function contains the main logic of the problem
void solve() {
	// Create an Io instance for reading input
	Io io;

	// Parse input using the NextInt function of the Io instance
	int X = io.NextInt();
	int N = io.NextInt();
	for (int i = 0; i < N; i++) {
		p[i] = io.NextInt();
	}

	// Check if X or its neighbors are present in the p slice
	for (int i = 0; i <= 100; i++) {
		if (find(X - i) == 1) {
			cout << X - i << endl;
			return;
		}
		if (find(X + i) == 1) {
			cout << X + i << endl;
			return;
		}
	}

	// OUTPUT GENERATION PART
	// ans := 0
	// cout << ans << endl;

	// If ans > 0, print "Yes" and exit; otherwise, print "No"
	// if (ans > 0) {
	//   cout << "Yes" << endl;
	// } else {
	//   cout << "No" << endl;
	// }
}

int main() {
	solve(); // Call the solve function
	return 0;
}

