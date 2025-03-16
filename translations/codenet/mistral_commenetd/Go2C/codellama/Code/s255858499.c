
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new scanner to read input from stdin
FILE *sc = stdin;

// Function to read a single line from stdin and return it as a string
char *nextLine() {
	// Declare a buffer to store the line read from stdin
	char *line = NULL;
	// Declare a variable to store the length of the line read from stdin
	size_t len = 0;
	// Read a line from stdin into the buffer
	getline(&line, &len, sc);
	// Return the line read from stdin as a string
	return line;
}

// Main function
int main() {
	// Set the scanner to split input on words
	// <NOT-IMPLEMENTED>

	// Read the first two integers from stdin and store them in variables a and b
	int a, b;
	a = atoi(nextLine()); // Convert the first line read from stdin to an integer and store it in variable a
	b = atoi(nextLine()); // Convert the second line read from stdin to an integer and store it in variable b

	// Check if the product of a and b is odd or even
	if (a*b%2 != 0) {
		// If the product is odd, print "Odd" to stdout
		printf("Odd\n");
	} else {
		// If the product is even, print "Even" to stdout
		printf("Even\n");
	}

	// Free the memory allocated for the line read from stdin
	free(line);

	// Return 0 to indicate successful execution
	return 0;
}

