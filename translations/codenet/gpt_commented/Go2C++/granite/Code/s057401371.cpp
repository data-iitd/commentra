
#include <iostream>
#include <string>

int main() {
	// Create a string variable to store the input text
	std::string s;
	
	// Read the input text from standard input
	std::getline(std::cin, s);

	// Calculate the difference between lowercase and uppercase letters
	int d = 'a' - 'A';
	
	// Iterate over each character in the input string
	for (char c : s) {
		// Initialize a variable to hold the modified character
		char cc = c;
		
		// Check if the character is an uppercase letter
		if ('A' <= c && c <= 'Z') {
			// Convert uppercase to lowercase by adding the difference
			cc = c + d;
		} else if ('a' <= c && c <= 'z') {
			// Convert lowercase to uppercase by subtracting the difference
			cc = c - d;
		}
		
		// Print the modified character
		std::cout << cc;
	}
	
	// Print a newline at the end of the output
	std::cout << std::endl;
	
	return 0;
}

