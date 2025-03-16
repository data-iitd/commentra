// Including the required header files
#include <iostream>
#include <string>

using namespace std;

int main() {
	// Declaring and initializing a string 's' for reading from standard input
	string s;
	cin >> s;

	// Declaring and initializing a variable 'd' with the value of 'a' - 'A'
	int d = 'a' - 'A';

	// Iterating through each character 'r' in the string 's'
	for (int i = 0; i < s.length(); i++) {
		// Declaring and initializing a variable 'rr' with the value of 'r'
		char rr = s[i];

		// Checking if the current character 'r' is an uppercase letter
		if ('A' <= rr && rr <= 'Z') {
			// If yes, adding the value of 'd' to 'r' and storing it in 'rr'
			rr = rr + d;
		} else if ('a' <= rr && rr <= 'z') {
			// If no, subtracting the value of 'd' from 'r' and storing it in 'rr'
			rr = rr - d;
		}

		// Printing the transformed character 'rr' to the standard output
		cout << rr;
	}

	// Printing a newline character after the transformation is complete
	cout << endl;

	return 0;
}

// End of the code 