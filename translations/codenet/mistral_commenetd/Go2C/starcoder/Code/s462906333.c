
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

// Constants and variables declaration
const int inf = INT_MAX;

// Function to read input from standard input using buffered scanner
typedef struct {
	int p;
	char *buf;
	size_t size;
	FILE *in;
} scanner;

// Creating a new scanner object
scanner *newScanner() {
	scanner *s = malloc(sizeof(scanner));
	s->in = stdin;
	s->size = 10000;
	s->buf = malloc(s->size);
	s->p = 0;
	return s;
}

// Function to read next token from input
char *next(scanner *s) {
	while (s->p < s->size && s->buf[s->p] =='') {
		s->p++;
	}
	char *start = s->p;
	while (s->p < s->size && s->buf[s->p]!='') {
		s->p++;
	}
	char *result = malloc(s->p - start + 1);
	memcpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++;
	return result;
}

// Function to read a complete line from input
char *Line(scanner *s) {
	while (s->p < s->size && s->buf[s->p] =='') {
		s->p++;
	}
	char *start = s->p;
	while (s->p < s->size && s->buf[s->p]!= '\n') {
		s->p++;
	}
	char *result = malloc(s->p - start + 1);
	memcpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++;
	return result;
}

// Function to read an integer from input
int Int(scanner *s) {
	char *token = next(s);
	int result = atoi(token);
	free(token);
	return result;
}

// Function to read an integer64 from input
int64_t Int64(scanner *s) {
	char *token = next(s);
	int64_t result = atoll(token);
	free(token);
	return result;
}

// Function to set the position of the reader to the beginning of the buffer
void pre(scanner *s) {
	if (s->p >= s->size) {
		readLine(s);
		s->p = 0;
	}
}

// Function to read a complete line from input and store it in the buffer
void readLine(scanner *s) {
	s->p = 0;
	s->size = 10000;
	free(s->buf);
	s->buf = malloc(s->size);
	while (true) {
		char *l = fgets(s->buf, s->size, s->in);
		if (l == NULL) {
			break;
		}
		if (l[0]!= '\n') {
			break;
		}
	}
}

// Main function
int main() {
	// Setting up logging
	setbuf(stdout, NULL);

	// Creating a new scanner object
	scanner *s = newScanner();

	// Reading input
	int n = Int(s);
	int x = Int(s);

	// Initializing arrays
	int *a = malloc(n * sizeof(int));
	int *v = malloc(n * sizeof(int));
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
}

// Helper functions
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// -------------------------------
// Function to check if a given number is inside a given range
bool in(int c, int a, int z) {
	return c >= a && c < z;
}

// Function to convert boolean value to integer
int btoi(bool b) {
	if (b) {
		return 1;
	}
	return 0;
}

// Function to convert integer value to boolean
bool itob(int a) {
	if (a == 0) {
		return false;
	}
	return true;
}

