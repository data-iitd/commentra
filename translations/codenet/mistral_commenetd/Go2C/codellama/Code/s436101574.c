
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a single string
char* scanString() {
	char* str = (char*)malloc(1000000 * sizeof(char));
	scanf("%s", str);
	return str;
}

// Function to read a single rune
char* scanRunes() {
	return scanString();
}

// Function to read a single integer
int scanInt() {
	int a;
	scanf("%d", &a);
	return a;
}

// Function to read a single integer64
long long scanInt64() {
	long long a;
	scanf("%lld", &a);
	return a;
}

// Function to read a single float64
double scanFloat64() {
	double a;
	scanf("%lf", &a);
	return a;
}

// Function to read multiple integers
int* scanInts(int n) {
	int* res = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		res[i] = scanInt();
	}
	return res;
}

// Function to print debug information
void debug(char* a, ...) {
	va_list args;
	va_start(args, a);
	vprintf(a, args);
	va_end(args);
}

// Function to get absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// Function to get minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to get maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Main function
int main() {
	// Reading input strings s and t
	char* s = scanRunes();
	char* t = scanRunes();

	// Initializing an empty slice to store answers
	char** ans = (char**)malloc(1000000 * sizeof(char*));
	int ans_len = 0;

	// Iterating through all possible substrings of s that have the same length as t
	for (int i = 0; i < strlen(s) - strlen(t) + 1; i++) {
		// Initializing a slice to store the modified string s
		char* ss = (char*)malloc(1000000 * sizeof(char));
		strcpy(ss, s);

		// Checking if the current substring matches the pattern t
		int f = 1;
		for (int j = 0; j < strlen(t); j++) {
			// If the current character of s does not match the current character of t or is not '?'
			if (ss[i + j] != t[j] && ss[i + j] != '?') {
				// Setting flag to false and breaking the loop
				f = 0;
				break;
			} else {
				// Replacing the current character of s with the corresponding character of t
				ss[i + j] = t[j];
			}
		}
		// If the current substring matches the pattern t
		if (f) {
			// Appending the modified string to the answer slice
			ans[ans_len++] = strdup(ss);
		}
	}
	// Sorting the answer slice in ascending order
	qsort(ans, ans_len, sizeof(char*), compare);
	// Checking if the answer slice is empty
	if (ans_len == 0) {
		// Printing "UNRESTORABLE" if the answer slice is empty
		printf("UNRESTORABLE\n");
	} else {
		// Printing the first element of the answer slice
		printf("%s\n", ans[0]);
	}
	// Freeing memory
	free(s);
	free(t);
	for (int i = 0; i < ans_len; i++) {
		free(ans[i]);
	}
	free(ans);
	return 0;
}

// Function to compare two strings
int compare(const void* a, const void* b) {
	return strcmp(*(char**)a, *(char**)b);
}

