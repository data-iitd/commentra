
#include <iostream>
#include <string>

int main() {
	std::string s; // Variable to store the input string
	std::cin >> s; // Read the input string from standard input

	for (int i = 0; i < s.length(); i++) { // Iterate over each character in the string
		if (s.substr(i + 1).find(s[i])!= std::string::npos) { // Check if the character appears again in the substring
			std::cout << "no" << std::endl; // If it does, print "no" and exit
			return 0;
		}
	}

	std::cout << "yes" << std::endl; // If no character appears again, print "yes"

	return 0;
}

