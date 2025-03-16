// Include the iostream header
#include <iostream>

// Include the string header
#include <string>

// Define the main function
int main() {
	// Declare two variables, n and s
	int n;
	std::string s;

	// Read the input from the standard input
	std::cin >> n >> s;

	// Print the result of the std::count function
	std::cout << std::count(s.begin(), s.end(), 'A') << std::endl;

	// Return 0
	return 0;
}

// This is the end of the code
