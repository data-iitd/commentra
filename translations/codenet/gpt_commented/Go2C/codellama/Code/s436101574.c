#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize scanner and writer for input and output
FILE *sc, *wr;

// Function to scan a single string from input
char *scanString() {
	char *s = malloc(10000 * sizeof(char));
	fscanf(sc, "%s", s);
	return s;
}

// Function to scan a slice of runes from input
char *scanRunes() {
	return scanString();
}

// Function to scan a single integer from input
int scanInt() {
	int a;
	fscanf(sc, "%d", &a);
	return a;
}

// Function to scan a single int64 from input
long long scanInt64() {
	long long a;
	fscanf(sc, "%lld", &a);
	return a;
}

// Function to scan a single float64 from input
double scanFloat64() {
	double a;
	fscanf(sc, "%lf", &a);
	return a;
}

// Function to scan n integers from input and return them as a slice
int *scanInts(int n) {
	int *res = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		res[i] = scanInt();
	}
	return res;
}

// Debug function to print messages to stderr
void debug(char *a, ...) {
	va_list args;
	va_start(args, a);
	vfprintf(stderr, a, args);
	va_end(args);
	fprintf(stderr, "\n");
}

// Function to return the absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// Function to return the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to return the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Main function where the program execution begins
int main() {
	// Ensure the buffered writer flushes its content before exiting
	setvbuf(wr, NULL, _IONBF, 0);

	// Set the scanner to split input by whitespace and configure buffer size
	sc = fopen("input.txt", "r");
	wr = fopen("output.txt", "w");

	// Read the first string of runes (s)
	char *s = scanRunes();
	// Read the second string of runes (t)
	char *t = scanRunes();

	// Initialize a slice to hold possible answers
	char **ans = malloc(10000 * sizeof(char *));
	int ans_len = 0;
	
	// Iterate through the first string to find occurrences of the second string
	for (int i = 0; i < strlen(s)-strlen(t)+1; i++) {
		int f = 1; // Flag to check if the current position is valid
		char *ss = malloc(10000 * sizeof(char)); // Create a copy of the original string
		strcpy(ss, s); // Copy the original string into ss

		// Check if the substring of s can match t
		for (int j = 0; j < strlen(t); j++) {
			// If characters do not match and are not '?', set flag to false
			if s[i+j] != t[j] && s[i+j] != '?' {
				f = 0;
				break;
			} else {
				// Replace '?' with the corresponding character from t
				ss[i+j] = t[j];
			}
		}
		// If the substring matched, replace remaining '?' with 'a' and store the result
		if (f) {
			ans[ans_len++] = strdup(str_replace(ss, "?", "a"));
		}
	}

	// Sort the possible answers
	qsort(ans, ans_len, sizeof(char *), cmp_str);

	// Output the result: either the first valid answer or "UNRESTORABLE"
	if (ans_len == 0) {
		fprintf(wr, "UNRESTORABLE\n");
	} else {
		fprintf(wr, "%s\n", ans[0]);
	}

	// Free memory
	free(s);
	free(t);
	for (int i = 0; i < ans_len; i++) {
		free(ans[i]);
	}
	free(ans);

	return 0;
}

// Function to replace all occurrences of a substring with another substring
char *str_replace(char *s, char *old, char *new) {
	char *res = malloc(10000 * sizeof(char));
	int i, j, k;
	for (i = j = 0; s[i] != '\0'; i++) {
		if (s[i] == old[j]) {
			j++;
			if (j == strlen(old)) {
				strcpy(res+i-j+1, new);
				i += strlen(new) - 1;
				j = 0;
			}
		} else {
			j = 0;
		}
	}
	return res;
}

// Function to compare two strings
int cmp_str(const void *a, const void *b) {
	return strcmp(*(char **)a, *(char **)b);
}

