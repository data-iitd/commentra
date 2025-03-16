// Importing required headers
#include <iostream>
#include <string>
#include <cstdlib>

// Creating a function to read a single line from stdin
std::string read() {
	std::string s; // Creating a string 's'
	std::getline(std::cin, s); // Reading a line from stdin and storing it in 's'
	return s; // Returning the value of 's'
}

// Main function
int main() {
	// Reading the first integer 'a' from stdin
	int a = std::atoi(read().c_str()); // Converting the read string to integer 'a'

	// Reading the second integer 'b' from stdin
	int b = std::atoi(read().c_str()); // Converting the read string to integer 'b'

	// Calculating the sum of 'a' and 'b'
	int ret = a + b;

	// Checking if the sum is less than the difference of 'a' and 'b'
	if (ret < (a - b)) {
		// If true, then update the value of 'ret'
		ret = a - b;
	}

	// Checking if the sum is less than the product of 'a' and 'b'
	if (ret < (a * b)) {
		// If true, then update the value of 'ret'
		ret = a * b;
	}

	// Printing the final value of 'ret'
	std::cout << ret << std::endl;

	// End of the code
	return 0;
}


