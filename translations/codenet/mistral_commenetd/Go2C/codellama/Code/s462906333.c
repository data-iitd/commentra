// Importing necessary packages
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants and variables declaration
const int inf = 1e14;

// Function to read input from standard input using buffered scanner
typedef struct {
	char *buf;
	int p;
	int n;
} scanner;

// Creating a new scanner object
scanner *newScanner() {
	scanner *s = (scanner *)malloc(sizeof(scanner));
	s->buf = (char *)malloc(10000 * sizeof(char));
	s->p = 0;
	s->n = 0;
	return s;
}

// Function to read next token from input
char *next(scanner *s) {
	while (s->buf[s->p] == ' ') {
		s->p++;
	}
	char *start = &s->buf[s->p];
	while (s->buf[s->p] != ' ' && s->buf[s->p] != '\0') {
		s->p++;
	}
	s->buf[s->p] = '\0';
	s->p++;
	return start;
}

// Function to read a complete line from input
char *line(scanner *s) {
	while (s->buf[s->p] != '\n' && s->buf[s->p] != '\0') {
		s->p++;
	}
	s->buf[s->p] = '\0';
	s->p++;
	return &s->buf[s->p - 1];
}

// Function to read an integer from input
int int(scanner *s) {
	return atoi(next(s));
}

// Function to read an integer64 from input
long long int int64(scanner *s) {
	return atoll(next(s));
}

// Function to set the position of the reader to the beginning of the buffer
void pre(scanner *s) {
	if (s->p >= s->n) {
		s->n = 0;
		s->p = 0;
		fgets(s->buf, 10000, stdin);
	}
}

// Function to read a complete line from input and store it in the buffer
void readLine(scanner *s) {
	s->n = 0;
	s->p = 0;
	fgets(s->buf, 10000, stdin);
}

// Main function
int main() {
	// Setting up logging
	// log.SetFlags(log.Lshortfile)

	// Creating a new scanner object
	scanner *next = newScanner();

	// Reading input
	int n = int(next);
	int x = int(next);

	// Initializing arrays
	int *a = (int *)malloc(n * sizeof(int));
	int *v = (int *)malloc(n * sizeof(int));
	memcpy(v, a, n * sizeof(int));

	// Initializing answer variable
	int ans = inf;

	// Iterating through all possible subarrays
	for (int k = 0; k < n; k++) {
		// Initializing variable to store sum of subarray elements
		int kans = 0;

		// Iterating through all elements of the subarray
		for (int i = 0; i < n; i++) {
			// Checking if current index is out of bounds for subarray
			if (i - k < 0) {
				// Updating current element in subarray with minimum of itself and corresponding element from the main array
				v[i] = min(v[i], a[n + i - k]);
			} else {
				// Updating current element in subarray with minimum of itself and previous element in subarray
				v[i] = min(v[i], a[i - k]);
			}

			// Adding current element to the sum of subarray
			kans += v[i];
		}

		// Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
		ans = min(ans, kans + k * x);
	}

	// Printing the answer
	printf("%d\n", ans);
	return 0;
}

// Helper functions
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to check if a given number is inside a given range
int in(int c, int a, int z) {
	return c >= a && c < z;
}

// Function to convert boolean value to integer
int btoi(int b) {
	if (b) {
		return 1;
	}
	return 0;
}

// Function to convert integer value to boolean
int itob(int a) {
	if (a == 0) {
		return 0;
	}
	return 1;
}

