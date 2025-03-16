
#include <iostream>

int main() {
	// Declare variables to hold input values
	int x, a, b;
	
	// Read three integer values from standard input
	std::cin >> x >> a >> b;
	
	// Evaluate the difference between b and a to determine the output
	if (b - a <= 0) {
		std::cout << "delicious" << std::endl; // Output "delicious" if b is less than or equal to a
	} else if (b - a <= x) {
		std::cout << "safe" << std::endl; // Output "safe" if the difference is within the limit x
	} else {
		std::cout << "dangerous" << std::endl; // Output "dangerous" if the difference exceeds x
	}
	
	return 0;
}
