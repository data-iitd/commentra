

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Read the first line of input (not used)
	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);

	// Read the second line of input which contains space-separated integers
	getline(&line, &len, stdin);
	char *ds = line;

	// Split the input string into a slice of strings
	char *dd[1000];
	int i = 0;
	while (1) {
		dd[i] = strsep(&ds, " ");
		if (dd[i] == NULL) {
			break;
		}
		i++;
	}

	// Create a slice of integers to hold the converted values
	int dn[1000];

	// Convert each string in the slice to an integer
	for (int i = 0; i < i; i++) {
		dn[i] = atoi(dd[i]);
	}

	// Initialize a variable to hold the sum of products
	int sum = 0;
	// Calculate the sum of products of all unique pairs of integers
	for (int i = 0; i < i; i++) {
		for (int j = i + 1; j < i; j++) {
			sum += dn[i] * dn[j]; // Multiply the pair and add to sum
		}
	}

	// Output the final sum of products
	printf("%d\n", sum);
}

