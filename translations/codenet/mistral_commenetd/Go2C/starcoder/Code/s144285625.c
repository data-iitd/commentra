
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Function to split input into words
void split(char *line, char **words) {
	char *pch;
	char *saveptr;
	pch = strtok_r(line, " ", &saveptr);
	int i = 0;
	while (pch!= NULL) {
		words[i] = pch;
		i++;
		pch = strtok_r(NULL, " ", &saveptr);
	}
}

// Function to read next integer from input
int nextInt() {
	// Reading next token as a string
	char *token;
	char *saveptr;
	char line[1000];
	fgets(line, 1000, stdin);
	token = strtok_r(line, " ", &saveptr);
	int i = atoi(token);
	return i;
}

// Main function
int main() {
	// Reading the number of elements in the array
	int n = nextInt();

	// Allocating memory for the array
	int *ar = (int *) malloc(3*n*sizeof(int));

	// Reading elements of the array
	for (int i = 0; i < 3*n; i++) {
		// Reading next integer and storing it in the array
		ar[i] = nextInt();
	}

	// Sorting the array in ascending order
	qsort(ar, 3*n, sizeof(int), (int (*)(const void *, const void *)) qsort_cmp);

	// Calculating the sum of elements at index 3n-2i-1 in the sorted array
	int sum = 0;
	for (int i = 0; i < n; i++) {
		// Adding the element at index 3n-2i-1 to the sum
		sum += ar[3*n-(i+1)*2];
	}

	// Printing the result
	printf("%d\n", sum);
}

