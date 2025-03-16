
#include <iostream>

// Array to store the count of each letter (a-z)
int c[26];

int main(void)
{
	// Array to store the input string
	char str[1200];
	
	// Read input strings until there are no more inputs
	while (std::cin >> str) {
		// Pointer to traverse the string
		char *p = str;
		
		// Traverse each character in the string
		for (; *p; p++) {
			// Check if the character is a lowercase letter
			if ('a' <= *p && *p <= 'z') {
				// Increment the count for the corresponding letter
				c[*p - 'a']++;
			} 
			// Check if the character is an uppercase letter
			else if ('A' <= *p && *p <= 'Z') {
				// Increment the count for the corresponding letter
				c[*p - 'A']++;
			}
		}
	}
	
	// Print the counts for each letter from 'a' to 'z'
	for (int i = 0; i < 26; i++) {
		std::cout << char('a' + i) << " : " << c[i] << std::endl; 
	}
	
	return 0;
}
