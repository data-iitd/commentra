
// Importing necessary packages
#include <iostream>

// Declaring variables
int main() {
	int x, a, b;

	// Reading input values from standard input
	std::cin >> x >> a >> b;

	// Logic block to check if b is less than or equal to a
	if (b - a <= 0) {
		std::cout << "delicious" << std::endl;
	} else if (b - a <= x) {
		std::cout << "safe" << std::endl;
	} else {
		std::cout << "dangerous" << std::endl;
	}

	// End of code
	return 0;
}