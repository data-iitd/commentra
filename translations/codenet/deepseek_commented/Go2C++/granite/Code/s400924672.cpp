
#include <iostream>

int main() {

	int r, D, x; // Declare integer variables for radius, D, and x
	std::cin >> r >> D >> x; // Read three integers from standard input

	for (int i = 1; i <= 10; i++) { // Loop 10 times
		std::cout << r*x - D << std::endl; // Print the result of the calculation
		x = r*x - D; // Update x for the next iteration
	}

	return 0;
}
