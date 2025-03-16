
#include <iostream>
#include <string>

int main() {
	std::string s; // Declare a variable to hold the input string
	std::cin >> s; // Read input from the user and store it in the variable's'

	for (int i = 0; i < s.length(); i++) {
		if (s.substr(i + 1).find(s[i])!= std::string::npos) {
			std::cout << "no" << std::endl; // If the character is found in the remaining substring, print "no" and exit
			return 0;
		}
	}

	std::cout << "yes" << std::endl; // If no duplicate characters were found, print "yes"
	return 0;
}

