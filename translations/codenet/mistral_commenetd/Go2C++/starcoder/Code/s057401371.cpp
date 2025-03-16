// Importing required packages
#include <iostream>
#include <string>

using namespace std;

// Function to transform the given string
string transform(string s) {
	// Declaring and initializing a variable 'd' with the value of 'a' - 'A'
	char d = 'a' - 'A';

	// Iterating through each character 'r' in the string's'
	for (int i = 0; i < s.length(); i++) {
		// Declaring and initializing a variable 'rr' with the value of 'r'
		char rr = s[i];

		// Checking if the current character 'r' is an uppercase letter
		if ('A' <= s[i] && s[i] <= 'Z') {
			// If yes, adding the value of 'd' to 'r' and storing it in 'rr'
			rr = s[i] + d;
		} else if ('a' <= s[i] && s[i] <= 'z') {
			// If no, subtracting the value of 'd' from 'r' and storing it in 'rr'
			rr = s[i] - d;
		}

		// Printing the transformed character 'rr' to the standard output
		cout << rr;
	}

	// Printing a newline character after the transformation is complete
	cout << endl;

	// Returning the transformed string
	return s;
}

// Driver code
int main() {
	// Reading the first line from standard input and storing it in the string's'
	string s;
	getline(cin, s);

	// Calling the function 'transform' to transform the string's'
	transform(s);

	// Returning from the driver code
	return 0;
}

// End of the code

