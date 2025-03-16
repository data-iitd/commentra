
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Scanner to read input from standard input
char *sc = NULL;

// Function to read a single line of input
char *read() {
	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	return line;
}

int main() {
	// Set the split function for the scanner to words
	sc = strtok(read(), " ");

	// Read the first integer from input
	int a = atoi(sc);
	// Read the second integer from input
	int b = atoi(strtok(NULL, " "));

	// Perform addition of the two integers
	int ret = a + b;

	// Check if the result is less than the difference between the two integers
	if (ret < (a - b)) {
		ret = a - b;
	}
	// Check if the updated result is less than the product of the two integers
	if (ret < (a * b)) {
		ret = a * b;
	}

	// Print the final result
	printf("%d\n", ret);

	return 0;
}

