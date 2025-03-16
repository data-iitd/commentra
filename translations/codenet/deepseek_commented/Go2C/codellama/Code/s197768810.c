#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a global scanner to read input efficiently
FILE *sc = stdin;

// readInt reads a single integer from the standard input
int readInt() {
	char *line = NULL;
	size_t size = 0;
	int i;

	// Read a line from the input
	getline(&line, &size, sc);

	// Convert the line to an integer
	i = atoi(line);

	// Free the memory allocated by getline
	free(line);

	return i;
}

// readFloat64 reads a single float64 from the standard input
float readFloat64() {
	char *line = NULL;
	size_t size = 0;
	float f;

	// Read a line from the input
	getline(&line, &size, sc);

	// Convert the line to a float64
	f = atof(line);

	// Free the memory allocated by getline
	free(line);

	return f;
}

// readString reads a single string from the standard input
char *readString() {
	char *line = NULL;
	size_t size = 0;

	// Read a line from the input
	getline(&line, &size, sc);

	// Remove the trailing newline character
	line[strcspn(line, "\n")] = 0;

	return line;
}

// Main function to execute the program
int main() {
	// Set the scanner to read words instead of lines
	sc = stdin;

	// Read two integers n and m from the input
	int n, m;
	n = readInt();
	m = readInt();

	// Initialize a slice to hold m integers
	int *a = (int *)malloc(n * sizeof(int));
	int sum = 0;

	// Read m integers into the slice a and calculate their sum
	for (int i = 0; i < m; i++) {
		a[i] = readInt();
		sum += a[i];
	}

	// Check if the sum of integers exceeds n
	if (sum > n) {
		// Print -1 if the sum exceeds n and exit
		printf("-1\n");
		return 0;
	}

	// Print the difference between n and the sum if it's within bounds
	printf("%d\n", n - sum);

	// Free the memory allocated by malloc
	free(a);

	return 0;
}

