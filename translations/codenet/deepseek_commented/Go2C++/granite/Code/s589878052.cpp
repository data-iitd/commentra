
#include <iostream> // Importing the iostream library for formatted I/O operations

int main() {
	int a, b, h; // Declaring three integer variables a, b, and h
	std::cin >> a >> b >> h; // Reading three integers from the standard input and storing them in a, b, and h

	std::cout << (a + b) * h / 2 << std::endl; // Calculating and printing the area of a trapezoid

	return 0; // Returning 0 to indicate successful program execution
}

