#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to read an integer as input
int scanInt() {
	int num;
	cin >> num;
	return num;
}

// Function to read a string as input
string scanString() {
	string str;
	cin >> str;
	return str;
}

// Function to read an array of integers as input
vector<int> scanInts(int n) {
	vector<int> sl(n);
	for (int i = 0; i < n; i++) {
		sl[i] = scanInt();
	}
	return sl;
}

// Function to read an array of strings as input
vector<string> scanStrings(int n) {
	vector<string> sl(n);
	for (int i = 0; i < n; i++) {
		sl[i] = scanString();
	}
	return sl;
}

// Main function to execute the program
int main() {
	// Read the first three integers as input
	int r, D, x = scanInt(), scanInt(), scanInt();

	// Iterate through a loop 10 times
	for (int i = 1; i <= 10; i++) {
		// Calculate the new value of x using the given formula
		x = r*x - D;

		// Print the value of x to the console
		cout << x << endl;
	}
}

// The end of the code

