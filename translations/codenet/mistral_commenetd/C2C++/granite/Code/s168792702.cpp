
#include <iostream>

// Include the standard input/output library

int main(void) {
	// Declare three integer variables: a, b, and c
	int a, b, c;

	// Use the std::cin function to read three integers from the standard input and store them in variables a, b, and c
	std::cin >> a >> b >> c;

	// Check if the condition a < b and b < c is true. If it is, print "Yes" to the standard output using the std::cout function. Otherwise, print "No"
	if (a < b && b < c) {
		std::cout << "Yes" << std::endl; // If the condition is true, print "Yes"
	} else {
		std::cout << "No" << std::endl; // If the condition is false, print "No"
	}

	// Return 0 to indicate successful execution of the program
	return 0;
}
