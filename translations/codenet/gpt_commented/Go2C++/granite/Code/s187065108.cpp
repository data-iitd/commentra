
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Create a new scanner to read input from standard input
#define sc cin

// scanInt reads an integer from input and returns it
int scanInt() {
	int num;
	sc >> num;
	return num;
}

// scanString reads a single string from input and returns it
string scanString() {
	string str;
	sc >> str;
	return str;
}

// scanInts reads 'n' integers from input and returns them as a vector
vector<int> scanInts(int n) {
	vector<int> sl(n);
	for (int i = 0; i < n; i++) {
		sc >> sl[i];
	}
	return sl;
}

// scanStrings reads 'n' strings from input and returns them as a vector
vector<string> scanStrings(int n) {
	vector<string> sl(n);
	for (int i = 0; i < n; i++) {
		sc >> sl[i];
	}
	return sl;
}

int main() {
	// Read three integers from input: r, D, and x
	int r, D, x;
	sc >> r >> D >> x;
	
	// Perform calculations and print the result for 10 iterations
	for (int i = 1; i <= 10; i++) {
		x = r*x - D; // Update x based on the formula
		cout << x << endl; // Print the current value of x
	}
}

