// Importing required packages
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the main function
int main() {
	// Declaring and initializing a variable 's' with the value of 'NULL'
	char *s = NULL;

	// Declaring and initializing a variable 'd' with the value of 'a' - 'A'
	int d = 'a' - 'A';

	// Reading the first line from standard input and storing it in the string 's'
	s = (char *) malloc(100 * sizeof(char));
	scanf("%s", s);

	// Iterating through each character 'r' in the string 's'
	for (int i = 0; i < strlen(s); i++) {
		// Declaring and initializing a variable 'rr' with the value of 'r'
		char rr = s[i];

		// Checking if the current character 'r' is an uppercase letter
		if ('A' <= rr && rr <= 'Z') {
			// If yes, adding the value of 'd' to 'r' and storing it in 'rr'
			rr = rr + d;
		} else if ('a' <= rr && rr <= 'z') {
			// If no, subtracting the value of 'd' from 'r' and storing it in 'rr'
			rr = rr - d;
		}

		// Printing the transformed character 'rr' to the standard output
		printf("%c", rr);
	}

	// Printing a newline character after the transformation is complete
	printf("\n");

	// Freeing the memory allocated for the string 's'
	free(s);

	// Returning 0 to indicate that the program executed successfully
	return 0;
}

// End of the code 