#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer from standard input
int nextInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function to read a string from standard input
char* nextStr() {
	char* s = (char*)malloc(1000 * sizeof(char));
	scanf("%s", s);
	return s;
}

// Main function
int main() {
	// Read the first string from standard input
	char* s = nextStr();

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
			printf("%c\n", c);
			return 0;
		}

		// Increment variable c
		c++;
	}

	// If no character from 'a' to 'z' is found in the string s, print "None"
	printf("None\n");

	// End of code
	return 0;
}

