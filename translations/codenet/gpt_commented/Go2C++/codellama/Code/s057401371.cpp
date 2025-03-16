
#include <iostream>
#include <string>

int main() {
	// Read the input string
	std::string s;
	std::cin >> s;
	
	// Calculate the difference between lowercase and uppercase letters
	int d = 'a' - 'A';
	
	// Iterate over each character in the input string
	for (int i = 0; i < s.length(); i++) {
		// Initialize a variable to hold the modified character
		char rr = s[i];
		
		// Check if the character is an uppercase letter
		if ('A' <= rr && rr <= 'Z') {
			// Convert uppercase to lowercase by adding the difference
			rr += d;
		} else if ('a' <= rr && rr <= 'z') {
			// Convert lowercase to uppercase by subtracting the difference
			rr -= d;
		}
		
		// Print the modified character
		std::cout << rr;
	}
	
	// Print a newline at the end of the output
	std::cout << std::endl;
	
	return 0;
}

