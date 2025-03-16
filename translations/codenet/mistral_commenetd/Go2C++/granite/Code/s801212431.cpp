

#include <bits/stdc++.h>

using namespace std;

const int initialBufSize = 1e4; // Initial buffer size
const int maxBufSize = 1e8; // Maximum buffer size

// Initialize scanner
istringstream sc(cin.rdbuf());

// Function to read next token as a string
string next() {
	string token;
	sc >> token; // Scan next token
	return token; // Return token as string
}

// Function to find minimum of two integers
int min(int x, int y) {
	// If x is greater than y, return y
	if (x > y) {
		return y;
	} else {
		// Otherwise, return x
		return x;
	}
}

int main() {
	// Read input string S
	string S = next();

	// Initialize variables l0 and l1 to store count of '0' and '1' respectively
	int l0 = 0, l1 = 0;

	// Iterate through each character in string S
	for (int i = 0; i < S.length(); i++) {
		// If current character is '0', increment l0
		if (S[i] == '0') {
			l0++;
		} else {
			// Otherwise, increment l1
			l1++;
		}
	}

	// Print result which is twice the minimum of l0 and l1
	cout << 2 * min(l0, l1) << endl; // Print result

	return 0;
}

