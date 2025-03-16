// Import the "iostream" package for input/output operations
#include <iostream>

using namespace std;

// Declare a main function
int main() {
	// Declare three integer variables "a", "b", and "c"
	int a, b, c;

	// Read three integer values from the standard input
	cin >> a >> b >> c;

	// Check if the condition "a < b && b < c" is true
	if (a < b && b < c) {
		// If the condition is true, print the string "Yes" to the standard output
		cout << "Yes" << endl;
	} else {
		// If the condition is false, print the string "No" to the standard output
		cout << "No" << endl;
	}

	// Return from the main function
	return 0;
}

// End of code

