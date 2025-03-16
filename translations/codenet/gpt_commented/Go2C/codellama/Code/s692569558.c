#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Create a new scanner to read input from standard input
	char *s = malloc(1000000);
	scanf("%[^\n]%*c", s);
	scanf("%[^\n]%*c", s);
	char *ds = s;

	// Split the input string into a slice of strings
	char **dd = malloc(1000000);
	int i = 0;
	char *token = strtok(ds, " ");
	while (token != NULL) {
		dd[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	// Create a slice of integers to hold the converted values
	int *dn = malloc(1000000);
	
	// Convert each string in the slice to an integer
	for (i = 0; i < 1000000; i++) {
		dn[i] = atoi(dd[i]);
	}

	// Initialize a variable to hold the sum of products
	int sum = 0;
	// Calculate the sum of products of all unique pairs of integers
	for (i = 0; i < 1000000; i++) {
		for (int j = i + 1; j < 1000000; j++) {
			sum += dn[i] * dn[j]; // Multiply the pair and add to sum
		}
	}

	// Output the final sum of products
	printf("%d\n", sum);
	return 0;
}
