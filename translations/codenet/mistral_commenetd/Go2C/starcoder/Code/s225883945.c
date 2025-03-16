
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a single word from the input
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
				} else {
					break;
				}
			} else {
				w = (char*) malloc(sizeof(char) * (i + 1));
				w[i] = '\0';
				break;
			}
		} else {
			w = (char*) realloc(w, sizeof(char) * (i + 1));
			w[i] = c;
		}
		i++;
	}
	return w;
}

// Function to read an integer from the input
int nextInt() {
	int n = 0;
	char* w = next();
	if (w!= NULL) {
		n = atoi(w);
		free(w);
	}
	return n;
}

// Function to read a float64 from the input
double nextFloat64() {
	double n = 0;
	char* w = next();
	if (w!= NULL) {
		n = atof(w);
		free(w);
	}
	return n;
}

// Function to read n integers from the input
int* nextInts(int n) {
	int* a = (int*) malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		a[i] = nextInt();
	}
	return a;
}

// Main function
int main() {
	// Read number of elements n and the sum of elements k from the input
	int n = nextInt();
	int k = nextInt();

	// Initialize a slice of size n to store the input elements
	int* a = (int*) malloc(sizeof(int) * n);

	// Assign a default value of 0 to the first element of the slice to avoid unused variable error
	a[0] = 0;

	// Initialize sum and answer variables
	int sum = 0;
	int ans = 1;

	// Use a loop to find the number of times k can be subtracted from n to reach a non-negative value
	for (sum = 0; sum < n; sum = sum - 1 + k) {
		// Increment the answer variable for each iteration
		ans++;
	}

	// Print the answer
	printf("%d\n", ans);

	// End of code
	return 0;
}

