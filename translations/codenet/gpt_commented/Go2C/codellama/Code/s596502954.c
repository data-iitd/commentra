#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a new scanner to read input from standard input
FILE *sc = stdin;

// next reads the next line of input and returns it as a string
char *next() {
	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, sc);
	return line;
}

// nextInt reads the next line of input, converts it to an integer, and returns it
int nextInt() {
	char *line = next();
	int i = atoi(line);
	free(line);
	return i;
}

// nextFloat64 reads the next line of input, converts it to a float64, and returns it
float nextFloat64() {
	char *line = next();
	float f = atof(line);
	free(line);
	return f;
}

// nextInts reads 'n' integers from input and returns them as a slice
int *nextInts(int n) {
	int *slice = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		slice[i] = nextInt();
	}
	return slice;
}

int main() {
	// Read two integers, sum them, and compare the result with a third integer
	if (nextInt() + nextInt() >= nextInt()) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}

