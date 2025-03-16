

#include <stdio.h> // Include the "stdio.h" header file for formatted I/O

int main() {
	// Declare a variable named "s" of type char array with a size of 5
	char s[5];

	// Use the "scanf" function to read a string input from the standard input
	scanf("%s", s);

	// Check if the length of the string "s" is greater than or equal to 4
	// and if its first four characters are "YAKI"
	if (strlen(s) >= 4 && strncmp(s, "YAKI", 4) == 0) {
		// If the condition is true, print the word "Yes" to the standard output
		printf("Yes\n");
	} else {
		// If the condition is false, print the word "No" to the standard output
		printf("No\n");
	}

	return 0; // Return 0 to indicate successful execution
}

