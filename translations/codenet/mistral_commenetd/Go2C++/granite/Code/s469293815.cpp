

#include <iostream>

int main() {
	// Declare and initialize three integer variables, A, B, and C, with values read from the standard input.
	int A, B, C;
	std::cin >> A >> B >> C;

	// Check if the sum of A and B is greater than or equal to C.
	if (A + B >= C) {
		// If the condition is true, print "Yes" to the standard output.
		std::cout << "Yes" << std::endl;
	} else {
		// If the condition is false, print "No" to the standard output.
		std::cout << "No" << std::endl;
	}

	return 0;
}
