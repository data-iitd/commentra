
#include <iostream> // Importing the iostream library for input/output operations

int main() {
	// Declare variables to hold the lengths of the two bases and the height
	int a, b, h;
	
	// Read input values for the two bases (a and b) and the height (h) from the user
	std::cin >> a >> b >> h;

	// Calculate the area of the trapezoid using the formula: Area = (a + b) * h / 2
	// and print the result to the console
	std::cout << (a + b) * h / 2 << std::endl;
}

