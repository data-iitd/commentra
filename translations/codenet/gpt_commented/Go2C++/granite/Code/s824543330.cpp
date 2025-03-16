
#include <iostream>

int main() {
	// Declare two integer variables to hold the input values
	int a, b;
	
	// Read two integers from standard input
	std::cin >> a >> b;

	// Check if the product of a and b is even or odd
	if (a*b%2 == 0) {
		// If the product is even, print "Even"
		std::cout << "Even" << std::endl;
	} else {
		// If the product is odd, print "Odd"
		std::cout << "Odd" << std::endl;
	}
}

