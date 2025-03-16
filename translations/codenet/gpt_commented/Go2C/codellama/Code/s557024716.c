
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants for general use
const int MOD = 1000000007; // Modulus value for calculations
const int ALPHABET_NUM = 26; // Number of letters in the alphabet
const int INF_INT64 = 9223372036854775807; // Maximum value for int64
const int INF_BIT60 = 1 << 60; // 60-bit integer limit
const int INF_INT32 = 2147483647; // Maximum value for int32
const int INF_BIT30 = 1 << 30; // 30-bit integer limit
const int NIL = -1; // Nil value for error handling

// Constants for graph algorithms (Dijkstra, Prim, etc.)
const int WHITE = 0; // Unvisited node
const int GRAY = 1; // Visited but not fully explored
const int BLACK = 2; // Fully explored node

// Function to generate all possible patterns of length k from the given elements.
void dupliRec(int *pattern, int *elems, int k, int *res, int *resSize) {
	if (k == 0) {
		res[*resSize] = *pattern; // Add the completed pattern to the result
		*resSize += 1; // Increment the result size
		return; // Return
	}

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			continue; // Skip if the pattern element is 0
		} else if (i == 1) {
			*pattern *= 2; // Double the red value
		} else if (i == 2) {
			*pattern *= 2; // Double the green value
		} else if (i == 3) {
			*pattern *= 2; // Double the blue value
		}

		// Recursively generate patterns with the new element added
		dupliRec(pattern, elems, k - 1, res, resSize);
	}
}

// Function to read an integer from input and handle errors
int readInt() {
	int i;
	char c;
	scanf("%d%c", &i, &c);
	if (c != '\n') {
		while (getchar() != '\n'); // Discard the rest of the line
		exit(EXIT_FAILURE); // Exit on error
	}
	return i; // Return the parsed integer
}

// Function to read an integer from input and handle errors
int readInt64() {
	int64_t i;
	char c;
	scanf("%lld%c", &i, &c);
	if (c != '\n') {
		while (getchar() != '\n'); // Discard the rest of the line
		exit(EXIT_FAILURE); // Exit on error
	}
	return i; // Return the parsed integer
}

// Function to read an integer from input and handle errors
int readFloat64() {
	double i;
	char c;
	scanf("%lf%c", &i, &c);
	if (c != '\n') {
		while (getchar() != '\n'); // Discard the rest of the line
		exit(EXIT_FAILURE); // Exit on error
	}
	return i; // Return the parsed integer
}

// Function to read an integer from input and handle errors
int readRune() {
	char c;
	scanf("%c", &c);
	return c; // Return the parsed integer
}

// Function to read a string from input and handle errors
char *readString() {
	char *str = NULL;
	int len = 0;
	int cap = 0;
	while (1) {
		str = realloc(str, ++cap * sizeof(char)); // Increment the capacity of the string
		if (!str) {
			exit(EXIT_FAILURE); // Exit on error
		}
		str[len] = readRune(); // Read a rune
		if (str[len] == '\n') {
			str[len] = '\0'; // Null-terminate the string
			return str; // Return the string
		}
		len++; // Increment the length of the string
	}
}

// Function to read an integer slice from input and handle errors
int *readIntSlice(int *n) {
	int *a = NULL;
	int len = 0;
	int cap = 0;
	while (1) {
		a = realloc(a, ++cap * sizeof(int)); // Increment the capacity of the slice
		if (!a) {
			exit(EXIT_FAILURE); // Exit on error
		}
		a[len] = readInt(); // Read an integer
		if (a[len] == -1) {
			*n = len; // Set the length of the slice
			return a; // Return the slice
		}
		len++; // Increment the length of the slice
	}
}

// Function to read an integer slice from input and handle errors
int64_t *readInt64Slice(int *n) {
	int64_t *a = NULL;
	int len = 0;
	int cap = 0;
	while (1) {
		a = realloc(a, ++cap * sizeof(int64_t)); // Increment the capacity of the slice
		if (!a) {
			exit(EXIT_FAILURE); // Exit on error
		}
		a[len] = readInt64(); // Read an integer
		if (a[len] == -1) {
			*n = len; // Set the length of the slice
			return a; // Return the slice
		}
		len++; // Increment the length of the slice
	}
}

// Function to read a float64 slice from input and handle errors
double *readFloat64Slice(int *n) {
	double *a = NULL;
	int len = 0;
	int cap = 0;
	while (1) {
		a = realloc(a, ++cap * sizeof(double)); // Increment the capacity of the slice
		if (!a) {
			exit(EXIT_FAILURE); // Exit on error
		}
		a[len] = readFloat64(); // Read a float64
		if (a[len] == -1) {
			*n = len; // Set the length of the slice
			return a; // Return the slice
		}
		len++; // Increment the length of the slice
	}
}

// Function to read a rune slice from input and handle errors
char *readRuneSlice() {
	char *str = NULL;
	int len = 0;
	int cap = 0;
	while (1) {
		str = realloc(str, ++cap * sizeof(char)); // Increment the capacity of the string
		if (!str) {
			exit(EXIT_FAILURE); // Exit on error
		}
		str[len] = readRune(); // Read a rune
		if (str[len] == '\n') {
			str[len] = '\0'; // Null-terminate the string
			return str; // Return the string
		}
		len++; // Increment the length of the string
	}
}

// Function to print an integer slice to output
void printIntSlice(int *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]); // Print each integer
	}
	printf("\n"); // Print a newline
}

// Function to print an integer slice to output
void printInt64Slice(int64_t *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%lld ", a[i]); // Print each integer
	}
	printf("\n"); // Print a newline
}

// Function to print a float64 slice to output
void printFloat64Slice(double *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%f ", a[i]); // Print each float64
	}
	printf("\n"); // Print a newline
}

// Function to print a rune slice to output
void printRuneSlice(char *str) {
	printf("%s\n", str); // Print the string
}

// Function to print a string to output
void printString(char *str) {
	printf("%s\n", str); // Print the string
}

// Function to print a newline to output
void printNewline() {
	printf("\n"); // Print a newline
}

// Function to print a debug message to output
void printDebug(char *msg) {
	printf("[DEBUG] %s\n", msg); // Print the debug message
}

// Function to print a debug message to output
void printDebugInt(char *msg, int i) {
	printf("[DEBUG] %s %d\n", msg, i); // Print the debug message
}

// Function to print a debug message to output
void printDebugInt64(char *msg, int64_t i) {
	printf("[DEBUG] %s %lld\n", msg, i); // Print the debug message
}

// Function to print a debug message to output
void printDebugFloat64(char *msg, double f) {
	printf("[DEBUG] %s %f\n", msg, f); // Print the debug message
}

// Function to print a debug message to output
void printDebugRune(char *msg, char c) {
	printf("[DEBUG] %s %c\n", msg, c); // Print the debug message
}

// Function to print a debug message to output
void printDebugString(char *msg, char *str) {
	printf("[DEBUG] %s %s\n", msg, str); // Print the debug message
}

// Function to print a debug message to output
void printDebugIntSlice(char *msg, int *a, int n) {
	printf("[DEBUG] %s ", msg); // Print the debug message
	printIntSlice(a, n); // Print the integer slice
}

// Function to print a debug message to output
void printDebugInt64Slice(char *msg, int64_t *a, int n) {
	printf("[DEBUG] %s ", msg); // Print the debug message
	printInt64Slice(a, n); // Print the integer slice
}

// Function to print a debug message to output
void printDebugFloat64Slice(char *msg, double *a, int n) {
	printf("[DEBUG] %s ", msg); // Print the debug message
	printFloat64Slice(a, n); // Print the float64 slice
}

// Function to print a debug message to output
void printDebugRuneSlice(char *msg, char *str) {
	printf("[DEBUG] %s %s\n", msg, str); // Print the debug message
}

// Function to print a debug message to output
void printDebugStringSlice(char *msg, char **a, int n) {
	printf("[DEBUG] %s ", msg); // Print the debug message
	for (int i = 0; i < n; i++) {
		printf("%s ", a[i]); // Print each string
	}
	printf("\n"); // Print a newline
}

// Function to print a debug message to output
void printDebugIntSliceSlice(char *msg, int **a, int n) {
	printf("[DEBUG] %s ", msg); // Print the debug message
	for (int i = 0; i < n; i++) {
		printIntSlice(a[i], n); // Print each integer slice
	}
	printf("\n"); // Print a newline
}

// Function to print a debug message to output
void printDebugInt64SliceSlice(char *msg, int64_t **a, int n) {
	printf("[DEBUG] %s ", msg); // Print the debug message
	for (int i = 0; i < n; i++) {
		printInt64Slice(a[i], n); // Print each integer slice
	}
	printf("\n"); // Print a newline
}

// Function to print a debug message to output
void printDebugFloat64SliceSlice(char *msg, double **a, int n) {
	printf("[DEBUG] %s ", msg); // Print the debug message
	for (int i = 0; i < n; i++) {
		printFloat64Slice(a[i], n); // Print each float64 slice
	}
	printf("\n"); // Print a newline
}

// Function to print a debug message to output
void printDebugRuneSliceSlice(char *msg, char **a, int n) {
	printf("[DEBUG] %s ", msg); // Print the debug message
	for (int i = 0; i < n; i++) {
		printRuneSlice(a[i]); // Print each rune slice
	}
	printf("\n"); // Print a newline
}

// Function to print a debug message to output
void printDebugStringSliceSlice(char *msg, char ***a, int n) {
	printf("[DEBUG] %s ", msg); // Print the debug message
	for (int i = 0; i < n; i++) {
		printStringSlice(a[i], n); // Print each string slice
	}
	printf("\n"); // Print a newline
}

// Function to print a debug message to output
void printDebugIntSliceSliceSlice(char *msg, int ***a, int n) {
	printf("[DEBUG] %s ", msg); // Print the debug message
	for (int i = 0; i < n; i++) {
		printIntSliceSlice(a[i], n); // Print each integer slice slice
	}
	printf("\n"); // Print a newline
}

// Function to print a debug message to output
void printDebugInt64SliceSliceSlice(char *msg, int64_t ***a, int n) {
	printf("[DEBUG] %s ", msg); // Print the debug message
	for (int i = 0; i < n; i++) {
		printInt64SliceSlice(a[i], n); // Print each integer slice slice
	}
	printf("\n"); // Print a newline
}

// Function to print a debug message to output
void printDebugF