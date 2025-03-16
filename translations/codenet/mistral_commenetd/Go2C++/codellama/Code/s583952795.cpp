
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

// Function to convert a number to its base-10 string representation
// with digit count K
string TenToN(int number, int n) {
	string s; // Initialize result string
	int tmp = number; // Initialize temporary variable

	// Repeat the following process until the number becomes less than N
	while (tmp >= n) {
		// Append the remainder of the division by N to the result string
		s = to_string(tmp % n) + s;

		// If the number is less than N, break the loop
		if (tmp < n) {
			break;
		}

		// Divide the number by N
		tmp /= n;
	}

	// Return the result string
	return s;
}

// Main function entry point
int main() {
	// Read input numbers N and K
	int N, K;
	cin >> N >> K;

	// Calculate the base-10 representation of N up to digit count K
	string s = TenToN(N, K);

	// Print the length of the calculated string
	cout << s.length() << endl;

	return 0;
}

// 