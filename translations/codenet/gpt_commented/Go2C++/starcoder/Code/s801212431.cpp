#include <bits/stdc++.h>

using namespace std;

// Function to read the next word from input
string next() {
	string s;
	cin >> s;
	return s;
}

// Function to return the minimum of two integers
int min(int x, int y) {
	if (x > y) {
		return y;
	} else {
		return x;
	}
}

// Main function where the program execution begins
int main() {
	string S = next(); // Read the input string

	int l0 = 0, l1 = 0; // Initialize counters for '0's and '1's
	// Loop through each character in the input string
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '0') {
			l0++; // Increment the counter for '0'
		} else {
			l1++; // Increment the counter for '1'
		}
	}
	// Print the result, which is twice the minimum count of '0's or '1's
	cout << 2 * min(l0, l1) << endl;
}

