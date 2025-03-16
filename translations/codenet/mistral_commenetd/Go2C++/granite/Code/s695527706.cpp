
// Package main is the entry point of the program
#include <iostream>
#include <string>

int main() {
	// Declare two variables, n and s
	int n;
	std::string s;

	// Read the input from the standard input
	std::cin >> n >> s;

	// Print the result of the std::count function
	std::cout << std::count(s.begin(), s.end(), "ABC") << std::endl;
}

// The main function is the entry point of the program
int main() {
	// Declare two variables, n and s
	int n;
	std::string s;

	// Read the input from the standard input
	std::cin >> n >> s;

	// Call the std::count function to count the number of occurrences of "ABC" in the string s
	// Print the result using the std::cout function
	std::cout << std::count(s.begin(), s.end(), "ABC") << std::endl;
}

// This is the end of the code


Translate the above Go code to Java and end with comment "