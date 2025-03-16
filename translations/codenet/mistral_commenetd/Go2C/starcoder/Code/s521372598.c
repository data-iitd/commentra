#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Function to calculate the absolute difference of a number
int abs(int n) {
	if (n < 0) {
		return -n;
	}
	return n;
}

// Function to solve the problem
void solve() {
	// Read the number of elements in the array
	int n = getInt();
	// Read the array elements
	int *as = getIntSlice(n);

	// Initialize an array xs of size n
	int *xs = (int *) malloc(n * sizeof(int));
	// Iterate through the array as and assign the value xs[i]
	for (int i = 0; i < n; i++) {
		xs[i] = as[i] - i + 1;
	}
	// Sort the array xs in ascending order
	qsort(xs, n, sizeof(int), compare);

	// Assign the middle element of the sorted array xs to variable b
	int b = xs[n/2];
	// Initialize variable ans with 0
	int ans = 0;
	// Iterate through the array xs and calculate the absolute difference between each element and b
	for (int i = 0; i < n; i++) {
		ans += abs(xs[i] - b);
	}
	// Print the answer
	printf("%d\n", ans);
}

// Function to compare two integers
int compare(const void *a, const void *b) {
	// Compare the two integers pointed to by a and b
	return *(int *) a - *(int *) b;
}

// -----------------------------------------

// Function to read an integer from standard input
int getInt() {
	int ret;
	scanf("%d", &ret);
	return ret;
}

// Function to read an array of n integers from standard input
int *getIntSlice(int n) {
	int *ret = (int *) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		ret[i] = getInt();
	}
	return ret;
}

// Function to read a string from standard input
char *getString() {
	char *ret = (char *) malloc(1000000);
	scanf("%s", ret);
	return ret;
}

// Function to read a rune string from standard input
int *getRunes() {
	char *s = getString();
	int *ret = (int *) malloc(sizeof(int) * (strlen(s) + 1));
	for (int i = 0; i < strlen(s); i++) {
		ret[i] = s[i];
	}
	ret[strlen(s)] = 0;
	return ret;
}

