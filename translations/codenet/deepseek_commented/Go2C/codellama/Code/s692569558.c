
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Create a new scanner to read from standard input
	char *s = malloc(1000000);
	
	// Read the first line of input (which we will ignore)
	fgets(s, 1000000, stdin);
	
	// Read the second line of input
	fgets(s, 1000000, stdin);
	
	// Split the input string into a slice of strings
	char *ds = strtok(s, " ");
	
	// Create a slice of integers to hold the converted values
	int *dn = malloc(1000000);
	
	// Convert each string in the slice to an integer
	int i = 0;
	while (ds != NULL) {
		dn[i] = atoi(ds);
		ds = strtok(NULL, " ");
		i++;
	}
	
	// Initialize the sum variable to hold the result
	int sum = 0;
	
	// Calculate the sum of the products of all pairs of integers in the slice
	for (i = 0; i < 1000000; i++) {
		for (int j = i + 1; j < 1000000; j++) {
			sum += dn[i] * dn[j];
		}
	}
	
	// Print the result
	printf("%d\n", sum);
	
	// Free the memory allocated for the slice
	free(dn);
	
	// Free the memory allocated for the scanner
	free(s);
	
	return 0;
}

