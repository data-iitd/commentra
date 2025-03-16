
#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;

	// Define the difference between lowercase and uppercase ASCII values
	int d = 'a' - 'A';

	// Iterate over each character in the input string
	for (int i = 0; i < s.length(); i++) {
		char r = s[i];
		// Check if the character is an uppercase letter
		if ('A' <= r && r <= 'Z') {
			// Convert uppercase to lowercase
			r += d;
		} else if ('a' <= r && r <= 'z') {
			// Convert lowercase to uppercase
			r -= d;
		}
		// Print the converted character
		std::cout << r;
	}
	std::cout << std::endl;
	return 0;
}

