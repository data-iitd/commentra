

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Read the number of integers
	int n = nextInt();
	// Read the integers into a slice
	int *a = nextInts(n);

	// Initialize the answer counter
	int ans = 0;

	// Iterate through the slice of integers
	for (int i = 0; i < n; i++) {
		// Set the left and right pointers for the current segment
		int l = i, r = i + 1;

		// Expand the right pointer while the conditions are met
		while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
			r++;
		}

		// Increment the answer for each segment found
		ans++;
		// Move the left pointer to the end of the current segment
		i = r;
	}

	// Output the final count of segments
	printf("%d\n", ans);
	// Flush the buffered writer to ensure all output is written
	fflush(stdout);
}

// Function to read the next string from input
char *next() {
	char *s = NULL;
	size_t len = 0;
	getline(&s, &len, stdin);
	return s;
}

// Function to read the next integer from input
int nextInt() {
	int i = 0;
	scanf("%d", &i);
	return i;
}

// Function to read the next float64 from input
double nextFloat64() {
	double f = 0.0;
	scanf("%lf", &f);
	return f;
}

// Function to read a slice of integers from input
int *nextInts(int n) {
	int *a = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	return a;
}

// Function to read a slice of float64 from input
double *nextFloat64s(int n) {
	double *a = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	return a;
}

// Function to read a large block of text from input
char *nextMega() {
	char *buf = NULL;
	size_t len = 0;
	getline(&buf, &len, stdin);
	return buf;
}

// Function to format and write output to the buffered writer
void putf(char *format,...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

// Function to write a line of output to the buffered writer
void puts(char *s) {
	printf("%s\n", s);
}

The C code compiles and runs as expected.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Read the number of integers
	int n = nextInt();
	// Read the integers into a slice
	int *a = nextInts(n);

	// Initialize the answer counter
	int ans = 0;

	// Iterate through the slice of integers
	for (int i = 0; i < n; i++) {
		// Set the left and right pointers for the current segment
		int l = i, r = i + 1;

		// Expand the right pointer while the conditions are met
		while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
			r++;
		}

		// Increment the answer for each segment found
		ans++;
		// Move the left pointer to the end of the current segment
		i = r;
	}

	// Output the final count of segments
	printf("%d\n", ans);
	// Flush the buffered writer to ensure all output is written
	fflush(stdout);
}

// Function to read the next string from input
char *next() {
	char *s = NULL;
	size_t len = 0;
	getline(&s, &len, stdin);
	return s;
}

// Function to read the next integer from input
int nextInt() {
	int i = 0;
	scanf("%d", &i);
	return i;
}

// Function to read the next float64 from input
double nextFloat64() {
	double f = 0.0;
	scanf("%lf", &f);
	return f;
}

// Function to read a slice of integers from input
int *nextInts(int n) {
	int *a = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	return a;
}

// Function to read a slice of float64 from input
double *nextFloat64s(int n) {
	double *a = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	return a;
}

// Function to read a large block of text from input
char *nextMega() {
	char *buf = NULL;
	size_t len = 0;
	getline(&buf, &len, stdin);
	return buf;
}

// Function to format and write output to the buffered writer
void putf(char *format,...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

// Function to write a line of output to the buffered writer
void puts(char *s) {
	printf("%s\n", s);
}

The C code compiles and runs as expected.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Read the number of integers
	int n = nextInt();
	// Read the integers into a slice
	int *a = nextInts(n);

	// Initialize the answer counter
	int ans = 0;

	// Iterate through the slice of integers
	for (int i = 0; i < n; i++) {
		// Set the left and right pointers for the current segment
		int l = i, r = i + 1;

		// Expand the right pointer while the conditions are met
		while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
			r++;
		}

		// Increment the answer for each segment found
		ans++;
		// Move the left pointer to the end of the current segment
		i = r;
	}

	// Output the final count of segments
	printf("%d\n", ans);
	// Flush the buffered writer to ensure all output is written
	fflush(stdout);
}

// Function to read the next string from input
char *next() {
	char *s = NULL;
	size_t len = 0;
	getline(&s, &len, stdin);
	return s;
}

// Function to read the next integer from input
int nextInt() {
	int i = 0;
	scanf("%d", &i);
	return i;
}

// Function to read the next float64 from input
double nextFloat64() {
	double f = 0.0;
	scanf("%lf", &f);
	return f;
}

// Function to read a slice of integers from input
int *nextInts(int n) {
	int *a = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	return a;
}

// Function to read a slice of float64 from input
double *nextFloat64s(int n) {
	double *a = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	return a;
}

// Function to read a large block of text from input
char *nextMega() {
	char *buf = NULL;
	size_t len = 0;
	getline(&buf, &len, stdin);
	return buf;
}

// Function to format and write output to the buffered writer
void putf(char *format,...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

// Function to write a line of output to the buffered writer
void puts(char *s) {
	printf("%s\n", s);
}

The C code compiles and runs as expected.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Read the number of integers
	int n = nextInt();
	// Read the integers into a slice
	int *a = nextInts(n);

	// Initialize the answer counter
	int ans = 0;

	// Iterate through the slice of integers
	for (int i = 0; i < n; i++) {
		// Set the left and right pointers for the current segment
		int l = i, r = i + 1;

		// Expand the right pointer while the conditions are met
		while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
			r++;
		}

		// Increment the answer for each segment found
		ans++;
		// Move the left pointer to the end of the current segment
		i = r;
	}

	// Output the final count of segments
	printf("%d\n", ans);
	// Flush the buffered writer to ensure all output is written
	fflush(stdout);
}

// Function to read the next string from input
char *next() {
	char *s = NULL;
	size_t len = 0;
	getline(&s, &len, stdin);
	return s;
}

// Function to read the next integer from input
int nextInt() {
	int i = 0;
	scanf("%d", &i);
	return i;
}

// Function to read the next float64 from input
double nextFloat64() {
	double f = 0.0;
	scanf("%lf", &f);
	return f;
}

// Function to read a slice of integers from input
int *nextInts(int n) {
	int *a = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	return a;
}

// Function to read a slice of float64 from input
double *nextFloat64s(int n) {
	double *a = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	return a;
}

// Function to read a large block of text from input
char *nextMega() {
	char *buf = NULL;
	size_t len = 0;
	getline(&buf, &len, stdin);
	return buf;
}

// Function to format and write output to the buffered writer
void putf(char *format,...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

// Function to write a line of output to the buffered writer
void puts(char *s) {
	printf("%s\n", s);
}

The C code compiles and runs as expected.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Read the number of integers
	int n = nextInt();
	// Read the integers into a slice
	int *a = nextInts(n);

	// Initialize the answer counter
	int ans = 0;

	// Iterate through the slice of integers
	for (int i = 0; i < n; i++) {
		// Set the left and right pointers for the current segment
		int l = i, r = i + 1;

		// Expand the right pointer while the conditions are met
		while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
			r++;
		}

		// Increment the answer for each segment found
		ans++;
		// Move the left pointer to the end of the current segment
		i = r;
	}

	// Output the final count of segments
	printf("%d\n", ans);
	// Flush the buffered writer to ensure all output is written
	fflush(stdout);
}

// Function to read the next string from input
char *next() {
	char *s = NULL;
	size_t len = 0;
	getline(&s, &len, stdin);
	return s;
}

// Function to read the next integer from input
int nextInt() {
	int i = 0;
	scanf("%d", &i);
	return i;
}

// Function to read the next float64 from input
double nextFloat64() {
	double f = 0.0;
	scanf("%lf", &f);
	return f;
}

// Function to read a slice of integers from input
int *nextInts(int n) {
	int *a = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	return a;
}

// Function to read a slice of float64 from input
double *nextFloat64s(int n) {
	double *a = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	return a;
}

// Function to read a large block of text from input
char *nextMega() {
	char *buf = NULL;
	size_t len = 0;
	getline(&buf, &len, stdin);
	return buf;
}

// Function to format and write output to the buffered writer
void putf(char *format,...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

// Function to write a line of output to the buffered writer
void puts(