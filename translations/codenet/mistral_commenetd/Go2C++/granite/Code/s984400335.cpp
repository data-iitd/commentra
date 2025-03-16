
// C++ code
#include <iostream>
#include <algorithm>

// Function declaration for finding the minimum number among given integers
int min(int a, int b) {
	// Returning the minimum value between 'a' and 'b'
	return std::min(a, b);
}

int main() {
	// Declaring three integer variables for reading input values
	int n, a, b;

	// Reading input values from the standard input using'std::cin' object
	std::cin >> n >> a >> b;

	// Printing the minimum value between 'n*a' and 'b' using'std::cout' object
	std::cout << min(n*a, b) << std::endl;

	// End of the code
	return 0;
}

// End of the code