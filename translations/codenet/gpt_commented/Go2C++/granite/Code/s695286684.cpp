
#include <iostream> // Importing the iostream library for input/output operations
#include <string>   // Importing the string library for string manipulation functions

int main() {
	std::string s; // Declare a variable's' to hold the input string

	// Read a string input from the user and store it in variable's'
	std::cin >> s;

	// Replace all occurrences of "2017" with "2018" in the input string and print the result
	std::cout << std::string(s).replace(0, s.length(), "2018") << std::endl;

	return 0; // Return 0 to indicate successful execution of the program
}

