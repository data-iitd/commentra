// Import the "iostream" package for input/output operations
#include <iostream>

using namespace std;

int main() {
	// Declare and initialize two integer variables "a" and "b"
	// by reading input values from the standard input using the "cin" object
	int a, b;
	cin >> a >> b;

	// Calculate the product of "a" and "b" and store it in a new variable "product"
	int product = a * b;

	// Check if the product is even or odd using an if statement
	if (product % 2 == 0) {
		// If the product is even, print the message "Even" to the standard output
		cout << "Even" << endl;
	} else {
		// If the product is odd, print the message "Odd" to the standard output
		cout << "Odd" << endl;
	}

	// Return from the function
	return 0;
}

// End of code

