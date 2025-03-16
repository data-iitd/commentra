
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Initialize a scanner for reading input from stdin
stringstream sc;

// Function to read the next string from stdin
string nextStr() {
	string s;
	sc >> s;
	return s;
}

// Function to read the next integer from stdin
int nextInt() {
	int i;
	sc >> i;
	return i;
}

// Main function to read input and process it
int main() {
	// Read the number of test cases
	int n = nextInt();

	// Initialize variables for processing the input
	int ans = 0;
	int aPrev = 0;

	// Process each test case
	for (int i = 0; i < n; i++) {
		// Read the next integer as 'a'
		int a = nextInt();

		// Check if 'a' is valid based on the conditions in the problem statement
		switch (true) {
		case a > i || a > aPrev + 1: // 'a' is not valid, print -1 and exit
			cout << -1 << endl;
			return 0;
		case a == aPrev + 1: // Increment the answer if 'a' is consecutive with the previous number
			ans++;
		default: // Add 'a' to the answer if it's not consecutive but greater than the previous number
			ans += a;
		}

		// Update the previous number
		aPrev = a;
	}

	// Print the final answer
	cout << ans << endl;

	// End of code
	return 0;
}

