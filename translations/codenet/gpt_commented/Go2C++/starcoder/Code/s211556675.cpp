#include <bits/stdc++.h>

using namespace std;

// I/O
// Template file for input output

// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

// Constants

// Functions

// Input functions
int nextInt() {
	int x;
	cin >> x;
	return x;
}

// Main function
int main() {
	// Read four integers from input
	int A, B, C, K;
	cin >> A >> B >> C >> K;

	// Determine the maximum value among A, B, and C
	int ma = max(A, B, C);
	int rest = 0; // Initialize the rest variable to hold the sum of the other two values

	// Calculate the sum of the two smaller values
	if (ma == A) {
		rest += B + C;
	} else if (ma == B) {
		rest += A + C;
	} else {
		rest += A + B;
	}

	// Double the maximum value K times
	for (int i = 1; i <= K; i++) {
		ma *= 2;
	}

	// Output the final result: doubled max value plus the sum of the other two
	cout << ma + rest << endl;
	return 0;
}

