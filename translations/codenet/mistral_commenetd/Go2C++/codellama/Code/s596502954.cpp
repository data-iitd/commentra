
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to read a single word as a string from the input
string next() {
	string word;
	cin >> word;
	return word;
}

// Function to read an integer from the input
int nextInt() {
	int i;
	cin >> i;
	return i;
}

// Function to read a float64 from the input
float nextFloat64() {
	float f;
	cin >> f;
	return f;
}

// Function to read n integers from the input and return as a slice
int* nextInts(int n) {
	int* slice = new int[n];
	for (int i = 0; i < n; i++) {
		slice[i] = nextInt();
	}
	return slice;
}

// Main function
int main() {
	// Read the first three integers from the input
	int a = nextInt();
	int b = nextInt();
	int c = nextInt();

	// Check if the condition is true
	if (a + b >= c) {
		// If true, print "Yes" to the output
		cout << "Yes" << endl;
	} else {
		// If false, print "No" to the output
		cout << "No" << endl;
	}

	// End of code
	return 0;
}

