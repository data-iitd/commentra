
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

// Define constants
#define N_MAX (100)
#define P_MAX (100)
#define DP_ARRAY_SIZE (N_MAX * P_MAX / 32 + 1)

// Define helper functions
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

// Function to find the last occurrence of a substring in a string
static char *strrstr(const char *string, const char *pattern) {
	size_t offset = 0;
	char *lastP = NULL;

	char *searchResult = NULL;
	while ((searchResult = strstr(&(string[offset]), pattern)) != NULL && string[offset] != '\0') {
		lastP = searchResult;
		offset++;
	}

	return lastP;
}

// Function to compare two pointers for qsort
int compare_f(const void *a, const void *b) {
	return *((size_t *)a) < *((size_t *)b) ? -1 : 1;
}

// Function to calculate the number of combinations of n items taken r at a time
static size_t comb(const size_t n, const size_t r) {
	size_t result = 1;

	for (size_t i = 0; i < r; i++) {
		result *= n - i;
		result /= i + 1;
	}

	return result;
}

// Function to find the greatest common divisor of two numbers
static uint64_t gcd(uint64_t m, uint64_t n)
{
	uint64_t temp;

	while (m%n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}

	return n;
}

int main(void) {
	// Define pattern base string
	const char patternBase[] = "keyence";
	char top[8], bottom[8];
	char S[101];

	// Read input string from standard input
	scanf("%s", S);

	// Calculate length of input string
	const size_t len = strlen(S);
	bool found = false;

	// Loop through each character in pattern base string
	for (size_t offset = 0; offset < strlen(patternBase); offset++) {
		// Copy substring up to current character to top variable
		strncpy(top, patternBase, offset);
		top[offset] = '\0';

		// Copy substring from current character to end of pattern base string to bottom variable
		strncpy(bottom, &(patternBase[offset]), strlen(patternBase) - offset);
		bottom[strlen(patternBase) - offset] = '\0';

		// Search for top substring in input string
		const char *topSearch = strstr(S, top);

		// If top substring is found
		if (topSearch != NULL) {
			// Search for bottom substring after top substring in input string
			const char *bottomSearch = strrstr(&(topSearch[offset]), bottom);

			// If bottom substring is found
			if (bottomSearch != NULL) {
				// Calculate number of separators between top and bottom substrings
				size_t sepCount = 0;

				// If topSearch is not the first occurrence of top substring in input string
				if (topSearch != S) {
					sepCount++;
				}

				// If topSearch is not the same as bottomSearch
				if (&(topSearch[offset]) != bottomSearch) {
					sepCount++;
				}

				// If bottomSearch is not the last character in input string
				if (bottomSearch[strlen(bottom)] != '\0') {
					sepCount++;
				}

				// If number of separators is less than or equal to 1
				if (sepCount <= 1) {
					found = true;
					break;
				}
			}
		}
	}

	// Print output based on whether pattern is found or not
	puts((found ? "YES" : "NO"));

	return 0;
}