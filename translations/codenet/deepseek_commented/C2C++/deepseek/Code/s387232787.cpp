#include <iostream>
#include <string>

// Array to store the count of each letter (a-z)
int c[26] = {0};

int main()
{
	// String to store the input string
	std::string str;
	
	// Read input strings until there are no more inputs
	while (std::cin >> str) {
		// Traverse each character in the string
		for (char &ch : str) {
			// Check if the character is a lowercase letter
			if ('a' <= ch && ch <= 'z') {
				// Increment the count for the corresponding letter
				c[ch - 'a']++;
			} 
			// Check if the character is an uppercase letter
			else if ('A' <= ch && ch <= 'Z') {
				// Increment the count for the corresponding letter
				c[ch - 'A']++;
			}
		}
	}
	
	// Print the counts for each letter from 'a' to 'z'
	for (int i = 0; i < 26; i++) {
		std::cout << static_cast<char>('a' + i) << " : " << c[i] << std::endl; 
	}
	
	return 0;
}
