#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Create a new scanner to read input from standard input (stdin)
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	// Set the scanner to split input by words
	char *token;

	// Initialize a 3x3 integer array to hold the input values
	int c[3][3];
	// Initialize arrays to hold differences for calculations
	int a[3], b[3];

	// Read 3x3 integers from input and populate the array 'c'
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			read = getline(&line, &len, stdin); // Read the next word from input
			token = strtok(line, " "); // Split the word by spaces
			c[i][j] = atoi(token); // Convert the word to an integer and store it in 'c'
		}
	}

	// Calculate the first differences based on the first row of 'c'
	b[0] = c[0][0] - a[0];
	b[1] = c[0][1] - a[0];
	b[2] = c[0][2] - a[0];

	// Calculate the differences for the second and third rows based on the first row
	a[1] = c[1][0] - c[0][0];
	a[2] = c[2][0] - c[0][0];

	// Check if the calculated differences are consistent across the matrix
	if (a[1] == c[1][1]-c[0][1] && a[1] == c[1][2]-c[0][2] &&
		a[2] == c[2][1]-c[0][1] && a[2] == c[2][2]-c[0][2]) {
		// If the conditions are met, print "Yes"
		printf("Yes\n");
	} else {
		// If the conditions are not met, print "No"
		printf("No\n");
	}

	return 0;
}
