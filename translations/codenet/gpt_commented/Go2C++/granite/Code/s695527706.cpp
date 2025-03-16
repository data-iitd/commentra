
#include <iostream> // Importing the iostream library for input/output operations
#include <string>   // Importing the string library for string manipulation functions

int main() {
	int n;            // Declare a variable n to hold the length of the string
	std::string s;   // Declare a variable s to hold the input string

	// Read input values for n and s from the standard input
	std::cin >> n >> s;

	// Count and print the number of occurrences of the substring "ABC" in the string s
	std::cout << std::count(s.begin(), s.end(), "ABC");

	return 0;
}
