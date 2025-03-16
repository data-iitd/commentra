
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Initialize a new scanner for reading input from standard input
FILE *sc = stdin;

// NextLine reads a line of text from stdin and returns it as a string.
char *NextLine() {
	char *str = NULL;
	size_t size = 0;
	getline(&str, &size, sc);
	return str;
}

// NextIntsLine reads a line of text consisting of integers separated by spaces from stdin.
// It then converts these strings to integers and returns them as a slice of integers.
int *NextIntsLine() {
	char *intsStr = NextLine(); // Read the line of integers
	char *tmp = strtok(intsStr, " "); // Split the line into individual string components
	int *ints = (int *)malloc(sizeof(int) * 100); // Allocate memory for the slice
	int i = 0;
	while (tmp != NULL) {
		ints[i] = atoi(tmp); // Convert each string to an integer
		i++;
		tmp = strtok(NULL, " "); // Get the next string
	}
	return ints;
}

// NextStringsLine reads a line of text consisting of strings separated by spaces from stdin.
// It returns these strings as a slice.
char **NextStringsLine() {
	char *stringsStr = NextLine(); // Read the line of strings
	char *tmp = strtok(stringsStr, " "); // Split the line into individual string components
	char **strs = (char **)malloc(sizeof(char *) * 100); // Allocate memory for the slice
	int i = 0;
	while (tmp != NULL) {
		strs[i] = tmp; // Append each string to the slice
		i++;
		tmp = strtok(NULL, " "); // Get the next string
	}
	return strs;
}

// NextRunesLine reads a line of text consisting of characters arranged continuously from stdin.
// It returns these characters as a slice of runes.
rune *NextRunesLine() {
	char *line = NextLine(); // Read the line of characters
	rune *runes = (rune *)malloc(sizeof(rune) * 100); // Allocate memory for the slice
	int i = 0;
	while (line[i] != '\0') {
		runes[i] = line[i]; // Convert each character to a rune
		i++;
	}
	return runes;
}

// Max returns the maximum integer from a variable number of input integers.
// This function requires at least one argument, otherwise it will panic.
int Max(int a, ...) {
	va_list args;
	va_start(args, a);
	int m = a;
	for (int i = 0; i < 100; i++) {
		int n = va_arg(args, int);
		if (m < n) {
			m = n;
		}
	}
	va_end(args);
	return m;
}

// Min returns the minimum integer from a variable number of input integers.
// This function requires at least one argument, otherwise it will panic.
int Min(int a, ...) {
	va_list args;
	va_start(args, a);
	int m = a;
	for (int i = 0; i < 100; i++) {
		int n = va_arg(args, int);
		if (m > n) {
			m = n;
		}
	}
	va_end(args);
	return m;
}

// PowInt calculates the power of an integer base raised to an integer exponent.
// It panics if either argument is negative.
int PowInt(int a, int e) {
	if (a < 0 || e < 0) {
		printf("[argument error]: PowInt does not accept negative integers");
		exit(1);
	}
	double fa = (double)a; // Convert base to float64
	double fe = (double)e; // Convert exponent to float64
	double fanswer = pow(fa, fe); // Calculate power
	return (int)fanswer; // Return the result as an integer
}

// AbsInt returns the absolute value of an integer.
int AbsInt(int a) {
	double fa = (double)a; // Convert integer to float64
	double fanswer = fabs(fa); // Calculate absolute value
	return (int)fanswer; // Return the result as an integer
}

// DeleteElement removes an element at a specified index from a slice of integers.
// It returns a new slice with the element removed.
int *DeleteElement(int *s, int i) {
	if (i < 0 || i >= 100) {
		printf("[index error]");
		exit(1);
	}
	int *n = (int *)malloc(sizeof(int) * 100); // Create a new slice with one less element
	for (int j = 0; j < i; j++) {
		n[j] = s[j]; // Append elements before the index
	}
	for (int j = i + 1; j < 100; j++) {
		n[j - 1] = s[j]; // Append elements after the index
	}
	return n; // Return the new slice
}

// Concat concatenates two slices of runes and returns a new slice.
rune *Concat(rune *s, rune *t) {
	rune *n = (rune *)malloc(sizeof(rune) * 100); // Create a new slice with combined length
	for (int i = 0; i < 100; i++) {
		n[i] = s[i]; // Append the first slice
	}
	for (int i = 0; i < 100; i++) {
		n[i] = t[i]; // Append the second slice
	}
	return n; // Return the concatenated slice
}

// Main function where the program execution begins
int x;

int main() {
	int *tmp = NextIntsLine(); // Read a line of integers
	x = tmp[0]; // Store the first integer in variable x
	int i = 1; // Initialize counter
	int sum = 0; // Initialize sum
	while (1) {
		sum += i; // Incrementally add to sum
		if (sum >= x) { // Check if sum has reached or exceeded x
			break; // Exit the loop if condition is met
		}
		i++; // Increment counter
	}
	printf("%d\n", i); // Print the result
	return 0;
}

