

#include <iostream>

int main() {
	// Code for A - Between Two Integers
	int A, B, C;
	std::cin >> A >> B >> C;

	// Read three integers A, B, and C from standard input
	// Check if C is between A and B (inclusive)
	if (C >= A && C <= B) {
		// If C is between A and B, print "Yes"
		std::cout << "Yes" << std::endl;
	} else {
		// If C is not between A and B, print "No"
		std::cout << "No" << std::endl;
	}
}

