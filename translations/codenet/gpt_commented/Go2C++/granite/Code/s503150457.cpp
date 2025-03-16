
#include <iostream>
#include <string>

int main() {
	// Declare three string variables to hold user input
	std::string s1, s2, s3;
	
	// Read three strings from standard input
	std::cin >> s1 >> s2 >> s3;

	// Convert the first character of each string to uppercase and concatenate them
	std::string result = std::toupper(s1[0]) + std::toupper(s2[0]) + std::toupper(s3[0]);
	
	// Print the concatenated result
	std::cout << result << std::endl;
	
	return 0;
}

