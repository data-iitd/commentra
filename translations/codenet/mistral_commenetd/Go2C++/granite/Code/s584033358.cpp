
// Import the "iostream" library for input and output operations
#include <iostream>

int main() {
	// Declare two integer variables "n" and "k"
	int n, k;

	// Read the values of "n" and "k" from the standard input
	std::cin >> n >> k;

	// Check if the value of "k" is less than or equal to the middle index of the array "n"
	if (k <= (n + n % 2) / 2) {
		// If the condition is true, print "YES" to the standard output
		std::cout << "YES" << std::endl;
	} else {
		// If the condition is false, print "NO" to the standard output
		std::cout << "NO" << std::endl;
	}

	// End of the code
	return 0;
}

// End of the code