// Package declaration
#include <iostream>

// Function definition for the main function
int main() {
	// Declaring variables r, D, and x of type int
	int r, D, x;

	// Reading input values for r, D, and x from the standard input
	std::cin >> r >> D >> x;

	// Comment for the for loop
	// Loop runs 10 times
	for (int i = 1; i <= 10; i++) {
		// Print the result of the current iteration
		std::cout << r * x - D << std::endl;

		// Update the value of x for the next iteration
		x = r * x - D;
	}

	// End of the code
	return 0;
}

// End of the code


