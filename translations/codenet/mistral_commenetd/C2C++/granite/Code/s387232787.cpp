

#include <iostream>

// Initialize an array 'c' of size 26 to store the count of each character.
int c[26];

int main(void)
{
	char str[1200]; // Declare a character array'str' of size 1200 to store the input string.

	// Use a loop to read strings from the standard input using cin.until('\n') until the end of file is reached.
	for (std::string line; std::getline(std::cin, line);) {
		// Initialize a pointer 'p' to traverse the string'str'.
		for (char *p = line.c_str(); *p; p++) {
			// Use nested if conditions to check if the current character is a lowercase or uppercase letter.
			if ('a' <= *p && *p <= 'z') {
				// Increment the count of the corresponding character in the 'c' array.
				c[*p - 'a']++;
			} else if ('A' <= *p && *p <= 'Z') {
				// Increment the count of the corresponding character in the 'c' array.
				c[*p - 'A']++;
			}

		}
	}
	// Use a loop to print the count of each character and its corresponding character.
	for (int i = 0; i < 26; i++) {
		std::cout << char('a' + i) << " : " << c[i] << std::endl; 
	}
	// Return 0 to indicate successful execution of the program.
	return 0;
}

