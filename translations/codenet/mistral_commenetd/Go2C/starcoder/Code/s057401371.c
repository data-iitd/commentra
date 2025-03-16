// Importing required packages
#include <stdio.h>

int main() {
	// Declaring and initializing a variable's' with the value of the first line of input
	char s[1000];
	scanf("%s", s);

	// Declaring and initializing a variable 'd' with the value of 'a' - 'A'
	int d = 'a' - 'A';

	// Iterating through each character 'r' in the string's'
	for (int i = 0; i < strlen(s); i++) {
		// Declaring and initializing a variable 'rr' with the value of 'r'
		char rr = s[i];

		// Checking if the current character 'r' is an uppercase letter
		if ('A' <= s[i] && s[i] <= 'Z') {
			// If yes, adding the value of 'd' to 'r' and storing it in 'rr'
			rr = s[i] + d;
		} else if ('a' <= s[i] && s[i] <= 'z') {
			// If no, subtracting the value of 'd' from 'r' and storing it in 'rr'
			rr = s[i] - d;
		}

		// Printing the transformed character 'rr' to the standard output
		printf("%c", rr);
	}

	// Printing a newline character after the transformation is complete
	printf("\n");
}

// End of the code

