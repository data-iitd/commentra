
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function is the entry point of the program
int main() {
	// Initialize variable N to store the number of elements in the array
	int N;
	scanf("%d", &N); // Read the number of elements from the standard input

	// Initialize a scanner to read words from the standard input
	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);
	// Set the split function of the scanner to split the input into words
	char **words = NULL;
	words = malloc(sizeof(char*) * N);
	int i = 0;
	for (char *word = strtok(line, " "); word!= NULL; word = strtok(NULL, " ")) {
		words[i++] = word;
	}

	// Initialize an array 'v' of size N to store the frequency of each element
	int *v = malloc(sizeof(int) * N);

	// Iterate through the input elements and update the frequency in the array 'v'
	for (int i = 1; i < N; i++) {
		// Read the next element from the standard input
		scanf("%d", &i);
		// Convert the string to integer 'a'
		int a = atoi(words[i]);
		// Update the frequency of the element 'a-1' in the array 'v'
		v[a-1]++;
	}

	// Iterate through the array 'v' and print each element to the standard output
	for (int i = 0; i < N; i++) {
		// Print each element to the standard output
		printf("%d\n", v[i]);
	}

	// End of the code
	return 0;
}

