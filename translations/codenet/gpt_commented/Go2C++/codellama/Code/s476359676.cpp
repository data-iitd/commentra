
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read the next string from input
string nextStr() {
	string s;
	getline(cin, s);
	return s;
}

// Function to read the next integer from input
int nextInt() {
	string s = nextStr();
	stringstream ss(s);
	int i;
	ss >> i;
	return i;
}

int main() {
	// Read the number of integers to process
	int n = nextInt();

	// Initialize variables for the answer and the previous integer
	int ans = 0;
	int aPrev = 0;

	// Loop through each integer input
	for (int i = 0; i < n; i++) {
		int a = nextInt(); // Read the next integer

		// Check conditions based on the current and previous integers
		switch (true) {
		case a > i || a > aPrev + 1: // If the current integer is greater than the index or previous integer + 1
			cout << -1 << endl; // Print -1 and exit if the condition is met
			return 0;
		case a == aPrev + 1: // If the current integer is exactly one more than the previous integer
			ans++; // Increment the answer
		default: // For all other cases
			ans += a; // Add the current integer to the answer
		}
		aPrev = a; // Update the previous integer to the current one
	}

	// Print the final answer
	cout << ans << endl;

	return 0;
}

