
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

// Initialize a global scanner to read input efficiently
istream& operator>>(istream& in, vector<int>& v) {
	string s;
	getline(in, s);
	stringstream ss(s);
	int n;
	while (ss >> n) {
		v.push_back(n);
	}
	return in;
}

// readInt reads a single integer from the standard input
int readInt() {
	int n;
	cin >> n;
	return n;
}

// readFloat64 reads a single float64 from the standard input
float readFloat64() {
	float f;
	cin >> f;
	return f;
}

// readString reads a single string from the standard input
string readString() {
	string s;
	getline(cin, s);
	return s;
}

// Main function to execute the program
int main() {
	// Set the scanner to read words instead of lines
	cin.sync_with_stdio(false);

	// Read two integers n and m from the input
	int n, m;
	cin >> n >> m;

	// Initialize a slice to hold m integers
	vector<int> a(n);
	int sum = 0;

	// Read m integers into the slice a and calculate their sum
	for (int i = 0; i < m; i++) {
		cin >> a[i];
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
	return 0;
}

