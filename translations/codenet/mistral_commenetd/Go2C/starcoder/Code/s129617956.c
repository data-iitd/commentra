
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	// Read an integer from standard input and initialize n and rt variables
	int n = atoi(readline());
	int rt = sqrt(n);

	// Initialize minimum factor with a large value
	int minf = 100;

	// Check divisibility for numbers from 1 to the square root of n
	for (int i = 1; i < rt+1; i++) {
		// Check if n is divisible by i
		if (n%i == 0) {
			// Calculate the number of digits in the divisor
			int b = n / i;
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			// Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit);
		}
	}

	// Print the result
	printf("%d\n", minf);
}

// Function to read a line from standard input
char* readline() {
	// Declare a pointer to a line
	char* line = NULL;

	// Read a line from standard input
	ssize_t len = getline(&line, NULL, stdin);

	// Check if the line was read successfully
	if (len == -1) {
		// Return NULL if an error occurred
		return NULL;
	}

	// Remove the newline character from the end of the line
	line[len - 1] = 0;

	// Return the line
	return line;
}

// Function to find the minimum of two integers
int min(int i, int j) {
	// Return the smaller of the two integers
	if (i > j) {
		return j;
	}
	return i;
}

