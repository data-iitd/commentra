#include <iostream>

int main() {
	// Declare three integer variables to hold the input values
	int a, b, c;
	
	// Read three integers from standard input
	std::cin >> a >> b >> c;

	// Check if the difference between the first two numbers is equal to the difference between the last two numbers
	if (b-a == c-b) {
		// If the differences are equal, print "YES"
		std::cout << "YES" << std::endl;
	} else {
		// If the differences are not equal, print "NO"
		std::cout << "NO" << std::endl;
	}

	return 0;
}

