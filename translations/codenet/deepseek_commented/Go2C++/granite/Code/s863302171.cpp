
#include <iostream>
#include <string>

int main() {
	// Declare a variable to store the input string
	std::string n;
	
	// Read a string input from the user and store it in `n`
	std::cin >> n;
	
	// Loop through the first three characters of the input string
	for (int i = 0; i < 3; i++) {
		// Check if the character at the current position is '7'
		if (n[i] == '7') {
			// If '7' is found, print "Yes" and exit the program
			std::cout << "Yes" << std::endl;
			return 0;
		}
	}
	
	// If the loop completes without finding a '7', print "No"
	std::cout << "No" << std::endl;
	
	// 