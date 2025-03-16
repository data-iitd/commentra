
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a single word as a string from the input
char* next() {
	char* w = NULL;
	int c = 0;
	int i = 0;
	while (1) {
		c = getchar();
		if (c =='' || c == '\n' || c == '\t' || c == EOF) {
			if (c == EOF) {
				if (i == 0) {
					return NULL;
				}
			}
			w = (char*) malloc(sizeof(char) * (i + 1));
			w[i] = '\0';
			break;
		}
		w = (char*) realloc(w, sizeof(char) * (i + 1));
		w[i] = c;
		i++;
	}
	return w;
}

// Function to read an integer from the input
int nextInt() {
	int n = 0;
	char* w = next();
	if (w == NULL) {
		return n;
	}
	n = atoi(w);
	free(w);
	return n;
}

// Function to read a float64 from the input
double nextFloat64() {
	double n = 0;
	char* w = next();
	if (w == NULL) {
		return n;
	}
	n = atof(w);
	free(w);
	return n;
}

// Function to read n integers from the input and return as a slice
int* nextInts(int n) {
	int* arr = (int*) malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextInt();
	}
	return arr;
}

// Main function
int main() {
	// Read the first three integers from the input
	int a = nextInt();
	int b = nextInt();
	int c = nextInt();

	// Check if the condition is true
	if (a + b >= c) {
		// If true, print "Yes" to the output
		printf("Yes\n");
	} else {
		// If false, print "No" to the output
		printf("No\n");
	}

	// End of code
	return 0;
}

