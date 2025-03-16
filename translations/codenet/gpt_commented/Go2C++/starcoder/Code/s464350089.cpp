#include <bits/stdc++.h>

using namespace std;

// Define a constant for the modulo value
const int mod = 1000000007;

// Function to read the next string from input
string next() {
	string s;
	cin >> s;
	return s;
}

// Function to read the next integer from input
int nextInt() {
	int n;
	cin >> n;
	return n;
}

int main() {
	// Read the values of h and n from input
	int h, n;
	cin >> h >> n;

	// Initialize a variable to accumulate the sum of integers
	int a = 0;

	// Loop to read n integers and accumulate their sum
	for (int i = 0; i < n; i++) {
		a += nextInt();
	}

	// Check if the accumulated sum is less than h
	if (h > a) {
		// If h is greater than the sum, print "No"
		cout << "No" << endl;
	} else {
		// Otherwise, print "Yes"
		cout << "Yes" << endl;
	}
}

