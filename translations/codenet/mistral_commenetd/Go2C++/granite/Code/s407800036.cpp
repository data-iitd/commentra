
// Import the "iostream" library for input/output operations
#include <iostream>

int main() {
	// Declare three integer variables named A, B, and C
	int A, B, C;

	// Use the "std::cin" object to read three integers from the standard input
	// and assign them to the variables A, B, and C respectively
	std::cin >> A >> B >> C;

	// Check if the value of C is within the range of A and B
	if (C >= A && C <= B) {
		// If it is, print "Yes" to the standard output
		std::cout << "Yes" << std::endl;
	} else {
		// Otherwise, print "No" to the standard output
		std::cout << "No" << std::endl;
	}

	// End of code
	return 0;
}

