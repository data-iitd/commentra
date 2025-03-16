
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function to check for errors and exit with error message if any
void check(int e) {
	if (e != 0) {
		cout << "error: " << e << endl;
		exit(1);
	}
}

// Main function
int main() {
	// Initialize a variable named 'sage' to store the first line read from standard input
	string sage;

	// Use a switch statement to determine the action based on the first line read
	switch (getline(cin, sage)) {
	case 1:
		// Print "Hello World" if the first line is "1"
		cout << "Hello World" << endl;
		break;
	case 2:
		// Initialize a variable named 'sum' to store the sum of two numbers
		int sum = 0;

		// Use a for loop to read and sum two numbers
		for (int i = 0; i < 2; i++) {
			// Read the next line from standard input
			getline(cin, sage);

			// Convert the next line to an integer and store it in a variable named 'num'
			int num = atoi(sage.c_str());

			// Check for errors and exit with error message if any
			check(num);

			// Add the current number to the sum
			sum += num;
		}

		// Print the sum of the two numbers
		cout << sum << endl;
		break;
	}

	return 0;
}

// End of code