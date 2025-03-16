#include <iostream>

int main() {
	int a; // Declare a variable 'a' of type int to store user input
	std::cin >> a; // Read an integer value from standard input and store it in 'a'

	// Calculate the area of a circle with radius 'a' using the formula: Area = 3 * a^2
	std::cout << 3 * a * a << std::endl; // Print the calculated area to the standard output
}

