#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// solve function computes the minimum total distance to a median value
void solve() {
	// Read the number of elements
	int n = getInt();
	// Read the integer slice of size n
	int *as = getIntSlice(n);

	// Create a new slice to store adjusted values
	int *xs = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		// Adjust each element by subtracting its index and adding 1
		xs[i] = as[i] - i + 1;
	}
	// Sort the adjusted values
	qsort(xs, n, sizeof(int), compare);

	// Find the median value from the sorted slice
	int b = xs[n / 2];
	int ans = 0;
	// Calculate the total distance from each element to the median
	for (int i = 0; i < n; i++) {
		ans += abs(xs[i] - b);
	}
	// Output the result
	printf("%d\n", ans);

	// Free the memory allocated for the slices
	free(as);
	free(xs);
}

// abs function returns the absolute value of an integer
int abs(int n) {
	if (n < 0) {
		return -n;
	}
	return n;
}

// compare function for qsort
int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

// getInt reads an integer from input
int getInt() {
	int ret;
	scanf("%d", &ret);
	return ret;
}

// getIntSlice reads a slice of integers from input
int *getIntSlice(int n) {
	int *ret = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		ret[i] = getInt(); // Read each integer
	}
	return ret;
}

// getString reads a string from input
char *getString() {
	char *ret = (char *)malloc(1000000 * sizeof(char));
	scanf("%s", ret);
	return ret;
}

// getRunes converts a string to a slice of runes
int *getRunes() {
	char *str = getString();
	int *ret = (int *)malloc(strlen(str) * sizeof(int));
	for (int i = 0; i < strlen(str); i++) {
		ret[i] = str[i]; // Convert string to runes
	}
	free(str);
	return ret;
}

// 