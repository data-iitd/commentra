
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <limits>
#include <climits>
#include <cstdint>
#include <bits/stdc++.h>

using namespace std;

// Function to read an integer from standard input
int readInt() {
	// Read a word from standard input
	string word;
	cin >> word;
	// Convert the read word to an integer
	int i = stoi(word);
	// Return the integer value
	return i;
}

// Function to read a float64 from standard input
float readFloat64() {
	// Read a word from standard input
	string word;
	cin >> word;
	// Convert the read word to a float64
	float f = stof(word);
	// Return the float64 value
	return f;
}

// Function to read a string from standard input
string readString() {
	// Read a word from standard input
	string word;
	cin >> word;
	// Return the read word as a string
	return word;
}

// Main function
int main() {
	// Set the scanner to read words as input
	// Read the number of elements n and the number of queries m from standard input
	int n, m;
	cin >> n >> m;
	// Allocate an array a of size n
	vector<int> a(n);
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
			cout << "-1" << endl;
			return 0;
		}
	}
	// Print the result, which is the difference between the size of the array and the sum of its elements
	cout << n - sum << endl;
	return 0;
}

