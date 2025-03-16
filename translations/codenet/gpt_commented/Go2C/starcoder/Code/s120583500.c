


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Declare a variable to hold the input string
	char s[1000];
	// Read input from the user
	scanf("%s", s);

	// Initialize a counter for consecutive valid characters and a slice to hold counts
	int count = 0;
	int *counter;

	// If the input string is empty, exit the function
	if (s[0] == '\0') {
		return 0;
	}

	// Start the counter with an initial value of 0
	counter = (int *) malloc(sizeof(int));
	counter[0] = 0;

	// Split the input string into a slice of individual characters
	char *li[1000];
	li = (char *) malloc(sizeof(char) * strlen(s));
	int i = 0;
	for (int j = 0; j < strlen(s); j++) {
		li[i] = (char *) malloc(sizeof(char));
		li[i][0] = s[j];
		i++;
	}

	// Iterate over each character in the slice
	for (int j = 0; j < i; j++) {
		// Check if the character is one of the valid DNA bases
		if (strcmp(li[j], "A") == 0 || strcmp(li[j], "C") == 0 || strcmp(li[j], "G") == 0 || strcmp(li[j], "T") == 0) {
			// Increment the count for consecutive valid characters
			count++;
		} else {
			// If an invalid character is encountered, store the current count
			counter = (int *) realloc(counter, sizeof(int) * (count + 1));
			counter[count] = count;
			// Reset the count for the next sequence
			count = 0;
		}
	}

	// Append the count of the last sequence of valid characters
	counter = (int *) realloc(counter, sizeof(int) * (count + 1));
	counter[count] = count;
	// Sort the counts to find the maximum consecutive valid characters
	qsort(counter, count + 1, sizeof(int), compare);
	// Print the maximum count of consecutive valid characters
	printf("%d", counter[count]);
	return 0;
}

int compare(const void *a, const void *b) {
	return *(int *) a - *(int *) b;
}

