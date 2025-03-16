#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next line of input and return it as a string
char* nextLine() {
	char* line = NULL;
	size_t size = 0;
	getline(&line, &size, stdin);
	return line;
}

int main() {
	// Set the scanner to split input by whitespace
	char* line = nextLine();
	char* token = strtok(line, " ");
	int a = atoi(token);
	token = strtok(NULL, " ");
	int b = atoi(token);

	// Check if the product of a and b is odd
	if (a*b % 2 != 0) {
		// If the product is odd, print "Odd"
		printf("Odd\n");
	} else {
		// If the product is even, print "Even"
		printf("Even\n");
	}

	// Free the memory allocated by getline
	free(line);
	return 0;
}

