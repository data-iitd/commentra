#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// mod is a global variable for storing a modulus value
int mod;

// intScanner reads an integer from input
int intScanner() {
	int n;
	scanf("%d", &n);
	return n;
}

// floatScanner reads a float64 from input
float floatScanner() {
	float n;
	scanf("%f", &n);
	return n;
}

// stringToInt converts a string to an integer
int stringToInt(char *s) {
	int n;
	sscanf(s, "%d", &n);
	return n;
}

// main function initializes the modulus value, sets up the bufio.Scanner, and reads the number of elements
int main(int argc, char *argv[]) {
	mod = 1000000007;
	int n = intScanner();
	int *as = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		as[i] = intScanner();
	}
	
	// Initialize xs with the first element of as
	int *xs = malloc(sizeof(int));
	xs[0] = as[0];
	for (int j = 1; j < n; j++) {
		// Use sort.Search to find the position to insert the current element
		int idx = sort(xs, 0, j, as[j]);
		if (idx == j) {
			// If the element is larger than all elements in xs, append it
			xs = realloc(xs, (j + 1) * sizeof(int));
			xs[j] = as[j];
		} else {
			// Otherwise, replace the existing element at the found position
			xs[idx] = as[j];
		}
	}
	
	// Print the length of the longest increasing subsequence found
	printf("%d\n", j);
	return 0;
}

// sort returns the index of the first element in xs that is larger than x
int sort(int *xs, int lo, int hi, int x) {
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (xs[mid] < x) {
			lo = mid + 1;
		} else {
			hi = mid;
		}
	}
	return lo;
}

