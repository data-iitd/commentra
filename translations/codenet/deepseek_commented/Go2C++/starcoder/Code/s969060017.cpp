#include <iostream>

int main() {
	// Declare two integer variables `a` and `b` to store input values
	int a, b;
	
	// Read two integers from the standard input and store them in `a` and `b`
	std::cin >> a >> b;
	
	// Check if `b` is divisible by `a` without a remainder
	if (b%a == 0) {
		// If `b` is divisible by `a`, print the sum of `a` and `b`
		std::cout << a + b << std::endl;
	} else {
		// If `b` is not divisible by `a`, print the difference between `b` and `a`
		std::cout << b - a << std::endl;
	}
}

