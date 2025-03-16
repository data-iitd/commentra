#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new scanner to read input from standard input
FILE *sc = stdin;

// Scanner function reads a line of input and returns it as a string
char *Scanner() {
	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, sc);
	return line;
}

// intScanner function reads an integer from input and returns it
int intScanner() {
	int n;
	scanf("%d", &n);
	return n;
}

// floatScanner function reads a float64 from input and returns it
float floatScanner() {
	float n;
	scanf("%f", &n);
	return n;
}

// stringToInt converts a string to an integer
int stringToInt(char *s) {
	int n = atoi(s);
	return n;
}

// Declare a variable for the modulus value
int mod;

int main() {
	// Set the modulus value to 1000000007
	mod = 1000000007;
	
	// Create a buffer for the scanner with a size limit defined by mod
	char *buf = (char *) malloc(mod * sizeof(char));
	
	// Set the scanner to split input by whitespace
	setvbuf(sc, buf, _IOFBF, mod);
	
	// Read the number of elements
	int n = intScanner();
	
	// Initialize a slice to hold the integers
	int *as = (int *) malloc(n * sizeof(int));
	
	// Read n integers from input
	for (int i = 0; i < n; i++) {
		as[i] = intScanner();
	}
	
	// Initialize a slice to hold the unique sorted integers
	int *xs = (int *) malloc(sizeof(int));
	xs[0] = as[0];
	
	// Iterate through the input integers starting from the second element
	for (int j = 1; j < n; j++) {
		// Use binary search to find the position to insert the current integer
		int idx = 0;
		for (int i = 0; i < j; i++) {
			if (as[j] < xs[i]) {
				idx = i;
				break;
			}
		}
		
		// If the index is equal to the length of xs, append the integer
		if (idx == j) {
			xs = (int *) realloc(xs, (j + 1) * sizeof(int));
			xs[j] = as[j];
		} else {
			// Otherwise, replace the existing integer at the found index
			xs[idx] = as[j];
		}
	}
	
	// Print the number of unique integers found
	printf("%d\n", j);
	
	// Free the memory allocated for the slices
	free(as);
	free(xs);
	free(buf);
	
	return 0;
}

