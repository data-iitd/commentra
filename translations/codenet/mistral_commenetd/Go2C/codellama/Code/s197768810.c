
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new scanner for reading input from stdin
FILE *sc = stdin;

// Function to read an integer from standard input
int readInt() {
	// Read a word from standard input
	char *word = malloc(sizeof(char) * 100);
	fscanf(sc, "%s", word);
	// Convert the read word to an integer
	int i = atoi(word);
	// If the conversion fails, panic with an error message
	if (i == 0 && word[0] != '0') {
		printf("Error: invalid input\n");
		exit(1);
	}
	// Return the integer value
	return i;
}

// Function to read a float64 from standard input
float readFloat64() {
	// Read a word from standard input
	char *word = malloc(sizeof(char) * 100);
	fscanf(sc, "%s", word);
	// Convert the read word to a float64
	float f = atof(word);
	// If the conversion fails, panic with an error message
	if (f == 0 && word[0] != '0') {
		printf("Error: invalid input\n");
		exit(1);
	}
	// Return the float64 value
	return f;
}

// Function to read a string from standard input
char *readString() {
	// Read a word from standard input
	char *word = malloc(sizeof(char) * 100);
	fscanf(sc, "%s", word);
	// Return the read word as a string
	return word;
}

// Main function
int main() {
	// Set the scanner to read words as input
	// sc = stdin;
	// Read the number of elements n and the number of queries m from standard input
	int n = readInt();
	int m = readInt();
	// Allocate an array a of size n
	int *a = malloc(sizeof(int) * n);
	// Initialize a variable sum to keep track of the sum of elements in the array
	int sum = 0;
	// Process each query
	for (int i = 0; i < m; i++) {
		// Read an integer from standard input and add it to the array a
		a[i] = readInt();
		// Add the current element to the sum
		sum += a[i];
		// Check if the sum is greater than the size of the array
		if (sum > n) {
			// If so, print -1 and exit the program
			printf("-1\n");
			return 0;
		}
	}
	// Print the result, which is the difference between the size of the array and the sum of its elements
	printf("%d\n", n - sum);
	return 0;
}

