
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to split input into words
void split(char *data) {
	char *token = strtok(data, " ");
	while (token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
}

// Function to read next integer from input
int nextInt() {
	// Reading next token as a string
	char *token = strtok(NULL, " ");
	// Converting the string to integer
	int i = atoi(token);
	return i;
}

// Main function
int main() {
	// Initializing scanner for reading input from stdin
	char *data = (char *)malloc(1000000 * sizeof(char));
	fgets(data, 1000000, stdin);
	split(data);

	// Reading the number of elements in the array
	int n = nextInt();

	// Allocating memory for the array
	int *ar = (int *)malloc(3 * n * sizeof(int));

	// Reading elements of the array
	for (int i = 0; i < 3 * n; i++) {
		// Reading next integer and storing it in the array
		ar[i] = nextInt();
	}

	// Sorting the array in ascending order
	qsort(ar, 3 * n, sizeof(int), compare);

	// Calculating the sum of elements at index 3n-2i-1 in the sorted array
	int sum = 0;
	for (int i = 0; i < n; i++) {
		// Adding the element at index 3n-2i-1 to the sum
		sum += ar[3 * n - (i + 1) * 2];
	}

	// Printing the result
	printf("%d\n", sum);

	return 0;
}

int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

