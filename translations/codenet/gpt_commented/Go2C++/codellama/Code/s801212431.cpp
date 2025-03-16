
#include <iostream>
#include <string>

using namespace std;

// Function to return the minimum of two integers
int min(int x, int y) {
	if (x > y) {
		return y; // Return y if x is greater
	} else {
		return x; // Return x otherwise
	}
}

// Main function where the program execution begins
int main() {
	string S; // Declare a string to store the input
	cin >> S; // Read the input string

	int l0, l1; // Initialize counters for '0's and '1's
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
	return 0;
}

