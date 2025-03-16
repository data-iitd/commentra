
#include <bits/stdc++.h>
using namespace std;

// Define constants for buffer sizes
const int initialBufSize = 1e4; // Initial buffer size for the scanner
const int maxBufSize = 1e8; // Maximum buffer size for the scanner

// Create a new scanner to read from standard input
istringstream sc(ios_base::in | ios_base::out);

// Initialize the scanner with a buffer and set the delimiter
void init() {
	string buf;
	buf.reserve(initialBufSize); // Reserve space for the buffer
	sc.str(buf); // Set the buffer as the input stream
	sc.clear(); // Clear any existing flags
	sc.imbue(locale("C")); // Set the locale to "C" for consistent behavior
	sc.exceptions(ios_base::goodbit); // Enable exception handling
	sc.unsetf(ios_base::skipws); // Disable whitespace skipping
	sc.precision(numeric_limits<double>::max_digits10); // Set the precision for floating-point numbers
	sc >> noskipws; // Disable whitespace skipping for the entire stream
}

// Function to read the next word from input
string next() {
	string word;
	sc >> word; // Read the next word from the input stream
	return word; // Return the read word as a string
}

// Function to return the minimum of two integers
int min(int x, int y) {
	return (x < y)? x : y; // Return the minimum of x and y
}

// Main function where the program execution begins
int main() {
	init(); // Initialize the scanner
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
	cout << 2 * min(l0, l1) << endl; // Output the result
	return 0; // Return 0 to indicate successful execution
}

