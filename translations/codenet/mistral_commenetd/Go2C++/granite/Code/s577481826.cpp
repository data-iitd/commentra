
// Importing required packages
#include <iostream>
#include <string>
#include <cstdlib>

// Main function
int main() {
	// Reading the first integer 'a' from stdin
	int a;
	std::cin >> a;

	// Reading the second integer 'b' from stdin
	int b;
	std::cin >> b;

	// Calculating the sum of 'a' and 'b'
	int ret = a + b;

	// Checking if the sum is less than the difference of 'a' and 'b'
	if (ret < (a - b)) {
		// If true, then update the value of'ret'
		ret = a - b;
	}

	// Checking if the sum is less than the product of 'a' and 'b'
	if (ret < (a * b)) {
		// If true, then update the value of'ret'
		ret = a * b;
	}

	// Printing the final value of'ret'
	std::cout << ret << std::endl;

	// End of the code
	return 0;
}
