

#include <iostream>
#include <string>

int main() {
	// Declare empty strings s1, s2, and s3 for user input
	std::string s1, s2, s3;

	// Read user input for strings s1, s2, and s3
	std::cin >> s1 >> s2 >> s3;

	// Declare strings s1s, s2s, and s3s to store individual characters of strings s1, s2, and s3 respectively
	std::string s1s = s1;
	std::string s2s = s2;
	std::string s3s = s3;

	// Print the concatenated uppercase first character of each string
	std::cout << std::toupper(s1s[0]) << std::toupper(s2s[0]) << std::toupper(s3s[0]) << std::endl;

	return 0;
}
