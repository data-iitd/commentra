
// Importing required packages
#include <iostream>
#include <string>

using namespace std;

int main() {
	// Declaring and initializing a string variable's' to store the input string
	string s;

	// Reading the input string from the standard input
	getline(cin, s);

	// Declaring and initializing a variable 'd' with the value of 'a' - 'A'
	int d = 'a' - 'A';

	// Iterating through each character 'r' in the string's'
	for (char& r : s) {
		// Declaring and initializing a variable 'rr' with the value of 'r'
		char rr = r;

		// Checking if the current character 'r' is an uppercase letter
		if ('A' <= r && r <= 'Z') {
			// If yes, adding the value of 'd' to 'r' and storing it in 'rr'
			rr = r + d;
		} else if ('a' <= r && r <= 'z') {
			// If no, subtracting the value of 'd' from 'r' and storing it in 'rr'
			rr = r - d;
		}

		// Printing the transformed character 'rr' to the standard output
		cout << rr;
	}

	// Printing a newline character after the transformation is complete
	cout << endl;

	// End of the code
	return 0;
}