

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Create a new scanner to read from standard input
	char line[1024];
	fgets(line, sizeof(line), stdin);
	
	// Read the second line of input
	fgets(line, sizeof(line), stdin);
	char *ds = line;
	
	// Split the input string into a slice of strings
	char *d = strtok(ds, " ");
	int *dn = malloc(sizeof(int) * 100);
	int i = 0;
	while (d!= NULL) {
		dn[i++] = atoi(d);
		d = strtok(NULL, " ");
	}
	
	// Initialize the sum variable to hold the result
	int sum = 0;
	
	// Calculate the sum of the products of all pairs of integers in the slice
	for (int i = 0; i < i; i++) {
		for (int j = i + 1; j < i; j++) {
			sum += dn[i] * dn[j];
		}
	}
	
	// Print the result
	printf("%d\n", sum);
	
	// Free the memory allocated for the slice of integers
	free(dn);
	
	return 0;
}
