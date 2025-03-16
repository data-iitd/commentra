#include <iostream> // Include the standard input/output stream library

int main() {
	int a, b, mawari, menseki; // Declare variables a, b, mawari, and menseki as integers

	// Read input values for variables a and b from the user
	std::cin >> a >> b;
	// Assign the variable mawari the sum of the squares of a and b
	mawari = a * a + b * b;
	// Assign the variable menseki the product of a and b
	menseki = a * b;
	// Print the values of menseki and mawari to the console
	std::cout << menseki << " " << mawari << std::endl;
	// Return 0 to indicate successful program execution
	return 0;
}
