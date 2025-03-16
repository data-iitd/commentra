
// Package main is the entry point of our C++ program
#include <iostream>
#include <string>

int main() {
	// Declare and initialize two variables: n of type int and s of type string
	int n;
	std::string s;

	// Use the std::cin object to read input from the standard input
	std::cin >> n;
	std::cin >> s;

	// Use the std::cout object to print the result
	std::cout << std::count(s.begin(), s.end(), "ABC") << std::endl;

	// End of code
	return 0;
}