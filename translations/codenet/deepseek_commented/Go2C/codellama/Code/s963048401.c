#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// sc is a global variable for reading input using bufio.Scanner
FILE *sc;

// Scanner reads a single line of input
char *Scanner() {
	char *s = malloc(1000000);
	fgets(s, 1000000, sc);
	return s;
}

// intScanner reads an integer from input
int intScanner() {
	int n;
	fscanf(sc, "%d", &n);
	return n;
}

// floatScanner reads a float64 from input
float floatScanner() {
	float n;
	fscanf(sc, "%f", &n);
	return n;
}

// stringToInt converts a string to an integer
int stringToInt(char *s) {
	int n;
	sscanf(s, "%d", &n);
	return n;
}

// mod is a global variable for storing a modulus value
int mod;

// main function initializes the modulus value, sets up the bufio.Scanner, and reads the number of elements
int main() {
	mod = 1000000007;
	sc = fopen("input.txt", "r");
	int n = intScanner();
	int *as = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		as[i] = intScanner();
	}
	
	// Initialize xs with the first element of as
	int *xs = malloc(sizeof(int));
	*xs = as[0];
	for (int j = 1; j < n; j++) {
		// Use sort.Search to find the position to insert the current element
		int idx = 0;
		while (idx < *xs && as[j] > xs[idx]) {
			idx++;
		}
		if (idx == *xs) {
			// If the element is larger than all elements in xs, append it
			xs = realloc(xs, (idx + 1) * sizeof(int));
			xs[idx] = as[j];
			*xs = idx + 1;
		} else {
			// Otherwise, replace the existing element at the found position
			xs[idx] = as[j];
		}
	}
	
	// Print the length of the longest increasing subsequence found
	printf("%d\n", *xs);
	
	// Free memory
	free(as);
	free(xs);
	
	// Close the file
	fclose(sc);
	
	return 0;
}

