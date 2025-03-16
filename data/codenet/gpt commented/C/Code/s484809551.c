#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

// Define constants for maximum sizes and array size for dynamic programming
#define N_MAX (100)
#define P_MAX (100)
#define DP_ARRAY_SIZE (N_MAX * P_MAX / 32 + 1)

// Define macros for common operations
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

// Function to find the last occurrence of a substring within a string
static char *strrstr(const char *string, const char *pattern) {
	size_t offset = 0;
	char *lastP = NULL;

	char *searchResult = NULL;
	// Loop to find the last occurrence of the pattern
	while ((searchResult = strstr(&(string[offset]), pattern)) != NULL && string[offset] != '\0') {
		lastP = searchResult; // Update last found position
		offset++; // Move offset to search for further occurrences
	}

	return lastP; // Return the last found position
}

// Comparison function for qsort, comparing two size_t values
int compare_f(const void *a, const void *b) {
	return *((size_t *)a) < *((size_t *)b) ? -1 : 1; // Return comparison result
}

// Function to calculate combinations C(n, r)
static size_t comb(const size_t n, const size_t r) {
	size_t result = 1;

	// Calculate the combination using the formula
	for (size_t i = 0; i < r; i++) {
		result *= n - i; // Multiply by decreasing values of n
		result /= i + 1; // Divide by increasing values of r
	}

	return result; // Return the result
}

// Function to compute the greatest common divisor (GCD) of two numbers
static uint64_t gcd(uint64_t m, uint64_t n) {
	uint64_t temp;

	// Euclidean algorithm to find GCD
	while (m % n != 0) {
		temp = n;
		n = m % n; // Update n to the remainder
		m = temp; // Update m to the previous n
	}

	return n; // Return the GCD
}

// Main function to execute the program
int main(void) {
	const char patternBase[] = "keyence"; // Define the pattern to search for
	char top[8], bottom[8]; // Buffers to hold split parts of the pattern
	char S[101]; // Buffer to hold the input string

	// Read the input string
	scanf("%s", S);

	const size_t len = strlen(S); // Get the length of the input string
	bool found = false; // Flag to indicate if the pattern is found

	// Loop through each possible split point in the pattern
	for (size_t offset = 0; offset < strlen(patternBase); offset++) {
		// Split the pattern into top and bottom parts
		strncpy(top, patternBase, offset);
		top[offset] = '\0'; // Null-terminate the top part
		strncpy(bottom, &(patternBase[offset]), strlen(patternBase) - offset);
		bottom[strlen(patternBase) - offset] = '\0'; // Null-terminate the bottom part

		// Search for the top part in the input string
		const char *topSearch = strstr(S, top);
		if (topSearch != NULL) {
			// Search for the bottom part after the found top part
			const char *bottomSearch = strrstr(&(topSearch[offset]), bottom);
			if (bottomSearch != NULL) {
				size_t sepCount = 0; // Counter for separators

				// Count the number of separators between top and bottom parts
				if (topSearch != S) {
					sepCount++; // Increment if there's text before the top part
				}
				if (&(topSearch[offset]) != bottomSearch) {
					sepCount++; // Increment if there's text between top and bottom parts
				}
				if (bottomSearch[strlen(bottom)] != '\0') {
					sepCount++; // Increment if there's text after the bottom part
				}

				// Check if the number of separators is less than or equal to 1
				if (sepCount <= 1) {
					found = true; // Set found flag to true
					break; // Exit the loop as the pattern is found
				}
			}
		}
	}

	// Output the result based on whether the pattern was found
	puts((found ? "YES" : "NO"));

	return 0; // Return success
}
