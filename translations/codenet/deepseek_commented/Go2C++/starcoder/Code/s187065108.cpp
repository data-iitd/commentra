#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Reads a single word from the input
string scanString() {
	string s;
	cin >> s;
	return s;
}

// Reads a slice of integers from input
vector<int> scanInts(int n) {
	vector<int> sl(n);
	for (int i = 0; i < n; i++) {
		cin >> sl[i];
	}
	return sl;
}

// Reads a slice of strings from input
vector<string> scanStrings(int n) {
	vector<string> sl(n);
	for (int i = 0; i < n; i++) {
		cin >> sl[i];
	}
	return sl;
}

// Main function to execute the program
int main() {
	// Read initial values for r, D, and x
	int r, D, x = scanInt(), scanInt(), scanInt();
	
	// Loop to calculate and print the values of x for 10 iterations
	for (int i = 1; i <= 10; i++) {
		x = r*x - D;
		cout << x << endl;
	}
}

