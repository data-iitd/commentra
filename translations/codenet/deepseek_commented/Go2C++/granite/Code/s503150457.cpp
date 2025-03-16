
#include <iostream>
#include <string>

int main() {
	// Declare three string variables to hold the input values
	std::string s1, s2, s3;
	
	// Read input values for s1, s2, and s3 from the standard input
	std::cin >> s1 >> s2 >> s3;

	// Split each input string into individual characters
	std::string s1s = s1;
	std::string s2s = s2;
	std::string s3s = s3;

	// Print the uppercase version of the first character of each input string
	std::cout << std::toupper(s1s[0]) << std::toupper(s2s[0]) << std::toupper(s3s[0]) << std::endl;
}

