
#include <iostream>
#include <string>

int main() {
	// Declare variables to hold the integer input and the string input
	int n;
	std::string s;
	
	// Read an integer from standard input
	std::cin >> n;
	
	// Read a string from standard input
	std::cin >> s;
	
	// Count the occurrences of the substring "ABC" in the input string
	// and print the result
	std::cout << std::count(s.begin(), s.end(), "ABC") << std::endl;
	
	return 0;
}
