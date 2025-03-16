#include <bits/stdc++.h>

using namespace std;

// Initialize a global scanner to read input efficiently
std::stringstream ss;
std::cin.tie(0);
std::ios_base::sync_with_stdio(false);

// readInt reads a single integer from the standard input
int readInt() {
	int n;
	ss >> n;
	return n;
}

// readFloat64 reads a single float64 from the standard input
double readFloat64() {
	double n;
	ss >> n;
	return n;
}

// readString reads a single string from the standard input
string readString() {
	string n;
	ss >> n;
	return n;
}

// Main function to execute the program
int main() {
	// Set the scanner to read words instead of lines
	ss.word(0);

	// Read two integers n and m from the input
	int n = readInt(), m = readInt();

	// Initialize a vector to hold m integers
	vector<int> a(m);
	int sum = 0;

	// Read m integers into the vector a and calculate their sum
	for (int i = 0; i < m; i++) {
		a[i] = readInt();
		sum += a[i];
	}

	// Check if the sum of integers exceeds n
	if (sum > n) {
		// Print -1 if the sum exceeds n and exit
		cout << "-1" << endl;
		return 0;
	}

	// Print the difference between n and the sum if it's within bounds
	cout << n - sum << endl;
}

