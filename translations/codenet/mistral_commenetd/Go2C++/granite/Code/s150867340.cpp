
// Import the "iostream" library for formatted I/O
#include <iostream>

int main() {
	// Declare and initialize two integer variables "a" and "b"
	// by reading input values from the standard input using the "std::cin" object
	int a, b;
	std::cin >> a >> b;

	// Calculate the product of "a" and "b" and store it in a new variable "product"
	int product = a * b;

	// Check if the product is even or odd using an if statement
	if (product % 2 == 0) {
		// If the product is even, print the message "Even" to the standard output
		std::cout << "Even" << std::endl;
	} else {
		// If the product is odd, print the message "Odd" to the standard output
		std::cout << "Odd" << std::endl;
	}

	// End of code
	return 0;
}