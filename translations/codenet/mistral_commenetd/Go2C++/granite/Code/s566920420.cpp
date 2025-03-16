

#include <iostream> // Include the "iostream" library for input/output operations

int main() {
	// Declare a variable named "a" of type int
	int a;

	// Read a value of type int from the standard input and store it in the variable "a"
	std::cin >> a;

	// Calculate the result of the expression "a + a*a + a*a*a"
	int result = a + a*a + a*a*a;

	// Print the result to the standard output
	std::cout << result << std::endl;

	// End of code
	return 0;
}

