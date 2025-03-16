
#include <bits/stdc++.h>

using namespace std;

// Initialize a new scanner for reading input from stdin
std::stringstream ss;
std::cin.rdbuf(ss.rdbuf());

// Function to read an integer from standard input
int readInt() {
	// Read a word from standard input
	std::cin >> std::ws;
	// Convert the read word to an integer
	int i;
	std::cin >> i;
	// Return the integer value
	return i;
}

// Function to read a float64 from standard input
double readFloat64() {
	// Read a word from standard input
	std::cin >> std::ws;
	// Convert the read word to a float64
	double f;
	std::cin >> f;
	// Return the float64 value
	return f;
}

// Function to read a string from standard input
std::string readString() {
	// Read a word from standard input
	std::cin >> std::ws;
	// Return the read word as a string
	return std::cin.get();
}

// Main function
int main() {
	// Read the number of elements n and the number of queries m from standard input
	int n, m = readInt(), readInt();
	// Allocate an array a of size n
	int a[n];
	// Initialize a variable sum to keep track of the sum of elements in the array
	int sum = 0;
	// Process each query
	for (int i = 0; i < m; i++) {
		// Read an integer from standard input and add it to the array a
		a[i] = readInt();
		// Add the current element to the sum
		sum += a[i];
		// Check if the sum is greater than the size of the array
		if (sum > n) {
			// If so, print -1 and exit the program
			std::cout << "-1" << std::endl;
			return 0;
		}
	}
	// Print the result, which is the difference between the size of the array and the sum of its elements
	std::cout << n - sum << std::endl;
	return 0;
}

