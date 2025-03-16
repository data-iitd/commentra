#include <iostream>
#include <string>

int main() {
	// Declare three string variables to hold user input
	std::string s1, s2, s3;
	
	// Read three strings from standard input
	std::cin >> s1 >> s2 >> s3;

	// Split each string into a slice of individual characters
	std::vector<char> s1s = s1;
	std::vector<char> s2s = s2;
	std::vector<char> s3s = s3;

	// Convert the first character of each string to uppercase and concatenate them
	std::string result = std::toupper(s1s[0]) + std::toupper(s2s[0]) + std::toupper(s3s[0]);
	
	// Print the concatenated result
	std::cout << result << std::endl;
}

