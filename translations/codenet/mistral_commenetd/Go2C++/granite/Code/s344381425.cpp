
// Import the "iostream" library for input/output operations
#include <iostream>

int main() {
	// Declare and initialize three integer variables "a", "b", and "c"
	// with values read from the standard input using the cin function
	int a, b, c;
	std::cin >> a >> b >> c;

	// Check if the condition "a < b && b < c" is true using an if statement
	if (a < b && b < c) {
		// If the condition is true, print the string "Yes" to the standard output
		std::cout << "Yes" << std::endl;
	} else {
		// If the condition is false, print the string "No" to the standard output
		std::cout << "No" << std::endl;
	}

	// Return from the main function
	return 0;
}

// End of code