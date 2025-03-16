
#include <iostream>

int main() {
	// Declare variables A, B, and C to hold integer values
	int A, B, C;
	
	// Read three integers from standard input
	std::cin >> A >> B >> C;

	// Check if C is within the range defined by A and B (inclusive)
	if (C >= A && C <= B) {
		// If C is within the range, print "Yes"
		std::cout << "Yes" << std::endl;
	} else {
		// If C is outside the range, print "No"
		std::cout << "No" << std::endl;
	}
}

