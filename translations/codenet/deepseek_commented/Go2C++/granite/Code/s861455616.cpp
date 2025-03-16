
#include <iostream>
#include <string>

int main() {
	// Declare a string variable to store user input
	std::string s;
	
	// Read a string input from the user and store it in `s`
	std::cin >> s;
	
	// Check if the length of `s` is at least 4 and if the first four characters are "YAKI"
	if (s.length() >= 4 && s.substr(0, 4) == "YAKI") {
		// If the condition is true, print "Yes"
		std::cout << "Yes" << std::endl;
	} else {
		// Otherwise, print "No"
		std::cout << "No" << std::endl;
	}
	
	// End of code
	return 0;
}
