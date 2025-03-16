
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the maximum count of nucleotides in any sub-sequence
int max(int a, int b) {
	// Return the maximum count of nucleotides in any sub-sequence
	return (a > b)? a : b;
}

// Function main is the entry point of the program
int main() {
	// Initialize an empty string variable's' to store the input DNA sequence
	char *s = NULL;

	// Read the input DNA sequence from the standard input using scanf() function
	scanf("%ms", &s);

	// Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T) in the current nucleotide sequence
	// and a pointer 'counter' to store the count of nucleotides in each sub-sequence between non-nucleotide characters
	int count = 0;
	int *counter = NULL;

	// Check if the input DNA sequence is empty or not
	if (s == NULL) {
		// If the input DNA sequence is empty, return without doing anything
		return 0;
	}

	// Initialize the first element of the 'counter' pointer with an initial count of 0
	counter = (int *) malloc(sizeof(int));
	*counter = 0;

	// Iterate through each character in the's' string using a for loop
	for (int i = 0; i < strlen(s); i++) {
		// Check if the current character is a valid nucleotide (A, C, G, T) or not
		if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
			// If the current character is a valid nucleotide, increment the 'count' variable
			count++;
		} else {
			// If the current character is not a valid nucleotide, append the current count to the 'counter' pointer and reset the 'count' variable to 0
			counter = (int *) realloc(counter, (i + 2) * sizeof(int));
			counter[i + 1] = count;
			count = 0;
		}
	}

	// Append the final count of nucleotides in the last sub-sequence to the 'counter' pointer
	counter = (int *) realloc(counter, (i + 2) * sizeof(int));
	counter[i + 1] = count;

	// Find the maximum count of nucleotides in any sub-sequence using the'max()' function
	int max_count = 0;
	for (int i = 0; i < strlen(s) + 1; i++) {
		// Find the maximum count of nucleotides in any sub-sequence
		max_count = max(max_count, counter[i]);
	}

	// Print the maximum count of nucleotides in any sub-sequence
	printf("%d", max_count);

	// Free the memory allocated to the 'counter' pointer
	free(counter);

	// Return from the function
	return 0;
}

