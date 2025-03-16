
// Importing required packages
#include <iostream>
#include <string>

// Declaring a variable 'a' of type string
int main() {
	std::string a;

	// Reading a string input from the user using std::cin
	std::cin >> a;

	// Declaring a temporary variable 'tmp' of type string
	std::string tmp = std::regex_replace(a, std::regex("1"), "0");

	// Replacing all occurrences of '1' with '0' in the string 'a'
	// and storing the result in the variable 'tmp'

	std::string b = std::regex_replace(tmp, std::regex("9"), "1");

	// Replacing all occurrences of '9' with '1' in the string 'tmp'
	// and storing the result in the variable 'b'

	std::string ans = std::regex_replace(b, std::regex("0"), "9");

	// Replacing all occurrences of '0' with '9' in the string 'b'
	// and storing the result in the variable 'ans'

	// Printing the final answer using std::cout
	std::cout << ans << std::endl;

	// Printing the final answer

	return 0;
}

// Printing the final answer