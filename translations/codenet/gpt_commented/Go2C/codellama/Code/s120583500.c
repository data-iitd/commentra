#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	// Declare a variable to hold the input string
	char s[1000];
	// Read input from the user
	scanf("%s", s);

	// Initialize a counter for consecutive valid characters and a slice to hold counts
	int count = 0;
	int *counter;
	counter = (int *)malloc(sizeof(int));
	counter[0] = 0;

	// If the input string is empty, exit the function
	if (strcmp(s, "") == 0) {
		return 0;
	}

	// Split the input string into a slice of individual characters
	char *li;
	li = strtok(s, "");

	// Iterate over each character in the slice
	while (li != NULL) {
		// Check if the character is one of the valid DNA bases
		if (strcmp(li, "A") == 0 || strcmp(li, "C") == 0 || strcmp(li, "G") == 0 || strcmp(li, "T") == 0) {
			// Increment the count for consecutive valid characters
			count++;
		} else {
			// If an invalid character is encountered, store the current count
			counter = (int *)realloc(counter, (sizeof(int) * (count + 1)));
			counter[count] = count;
			// Reset the count for the next sequence
			count = 0;
		}
		li = strtok(NULL, "");
	}

	// Append the count of the last sequence of valid characters
	counter = (int *)realloc(counter, (sizeof(int) * (count + 1)));
	counter[count] = count;
	// Sort the counts to find the maximum consecutive valid characters
	qsort(counter, count, sizeof(int), compare);
	// Print the maximum count of consecutive valid characters
	printf("%d\n", counter[count - 1]);
	return 0;
}

int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

