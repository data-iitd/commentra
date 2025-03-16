

#include <iostream>

int main() {
	// Declare two integer variables 'a' and 'b'
	int a, b;

	// Read two integer values from the user input using std::cin
	std::cin >> a >> b;

	// Check if 'b' is divisible by 'a' using if statement
	if (b % a == 0) {
		// If 'b' is divisible by 'a', print the sum of 'a' and 'b'
		std::cout << a + b << std::endl;
	} else {
		// If 'b' is not divisible by 'a', print the difference between 'b' and 'a'
		std::cout << b - a << std::endl;
	}

	return 0;
}
