#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Initialize variable s
	char s[100000];

	// Read the first string from standard input
	scanf("%s", s);

	// Initialize variable c with 'a'
	char c = 'a';

	// Check all characters from 'a' to 'z' in the string s
	for (int j = 0; j < 26; j++) {
		// Initialize variable found as false
		int found = 0;

		// Iterate through each character in the string s
		for (int i = 0; i < strlen(s); i++) {
			// If current character matches c, set found to true and break the loop
			if (s[i] == c) {
				found = 1;
				break;
			}
		}

		// If character c is not found in the string s, print it and return
		if (found == 0) {
			printf("%c", c);
			return 0;
		}

		// Increment variable c
		c++;
	}

	// If no character from 'a' to 'z' is found in the string s, print "None"
	printf("None");
}

