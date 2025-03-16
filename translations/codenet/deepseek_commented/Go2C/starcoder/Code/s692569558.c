
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	// Read the first line of input (which we will ignore)
	char *ds = NULL;
	size_t len = 0;
	getline(&ds, &len, stdin);
	
	// Read the second line of input
	getline(&ds, &len, stdin);
	
	// Split the input string into a slice of strings
	char *dd[100];
	int i = 0;
	for (char *p = strtok(ds, " "); p!= NULL; p = strtok(NULL, " ")) {
		dd[i++] = p;
	}
	
	// Create a slice of integers to hold the converted values
	int dn[100];
	
	// Convert each string in the slice to an integer
	for (int i = 0; i < 100; i++) {
		dn[i] = atoi(dd[i]);
	}
	
	// Initialize the sum variable to hold the result
	int sum = 0;
	
	// Calculate the sum of the products of all pairs of integers in the slice
	for (int i = 0; i < 100; i++) {
		for (int j = i + 1; j < 100; j++) {
			sum += dn[i] * dn[j];
		}
	}
	
	// Print the result
	printf("%d\n", sum);
	
	// Free the memory allocated for the input string
	free(ds);
	
	return EXIT_SUCCESS;
}

