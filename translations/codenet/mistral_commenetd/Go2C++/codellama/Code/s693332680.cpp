// Importing necessary packages
#include <iostream>

// Declaring variables
int main() {
	int x, a, b;

	// Reading input values from standard input
	std::cin >> x >> a >> b;

	// Logic block to check if b is less than or equal to a
	switch (b-a) {
		// Base case: If b is less than or equal to a
		case 0:
			std::cout << "delicious" << std::endl;
			break;

		// Next case: If b is greater than a but less than or equal to x
		case 1:
			std::cout << "safe" << std::endl;
			break;

		// Default case: If none of the above conditions are met
		default:
			std::cout << "dangerous" << std::endl;
			break;
	}

	return 0;
}

// End of code


