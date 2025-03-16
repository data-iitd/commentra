#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

// mainFn is the main logic of the program.
void mainFn() {
	// Get the number of elements in the slice.
	int n = getInt();
	// Get the slice of integers.
	int *ls = getIntSlice(n);
	// Create a reversed version of the slice.
	int *lsRev = (int *)malloc(n * sizeof(int));
	memcpy(lsRev, ls, n * sizeof(int));
	// Sort the original slice in ascending order.
	qsort(ls, n, sizeof(int), compareInt);
	// Sort the reversed slice in descending order.
	qsort(lsRev, n, sizeof(int), compareIntRev);

	// Initialize the answer variable.
	int ans = 0;
	// Loop through the slice to calculate the answer.
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// Calculate p and q based on the current elements.
			int p, q;
			if (ls[i] < ls[j]) {
				p = ls[i];
				q = ls[j];
			} else {
				p = ls[j];
				q = ls[i];
			}
			// Calculate x and y based on p and q.
			int x = q - p;
			int y = q + p;

			// Find the left boundary using binary search.
			int l = binarySearch(ls, n, x);
			// Find the right boundary using binary search.
			int r = n - binarySearch(lsRev, n, y);

			// Calculate the sum of valid pairs.
			int sum = r - l;
			// Adjust the sum if the current indices are within the range.
			if ((i >= l) && (i <= r)) {
				sum--;
			}
			if ((j >= l) && (j <= r)) {
				sum--;
			}
			// Ensure the sum is not negative.
			sum = max(0, sum);
			// Add the sum to the answer.
			ans += sum;
		}
	}

	// Divide the answer by 3 to get the final result.
	ans /= 3;
	// Print the final answer.
	puts(ans);
}

// Helper functions to find the minimum and maximum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// -----------------------------------------

// Global variables for input/output operations.
FILE *inputFile;
FILE *outputFile;

// getInt reads an integer from the standard input.
int getInt() {
	int i;
	fscanf(inputFile, "%d", &i);
	return i;
}

// getIntSlice reads a slice of integers from the standard input.
int *getIntSlice(int n) {
	int *is = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		fscanf(inputFile, "%d", &is[i]);
	}
	return is;
}

// getString reads a string from the standard input.
char *getString() {
	char *s = (char *)malloc(100001 * sizeof(char));
	fscanf(inputFile, "%s", s);
	return s;
}

// puts writes the arguments to the standard output.
void puts(int a) {
	fprintf(outputFile, "%d\n", a);
}

// -----------------------------------------

// compareInt is a helper function to compare two integers.
int compareInt(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

// compareIntRev is a helper function to compare two integers in descending order.
int compareIntRev(const void *a, const void *b) {
	return (*(int *)b - *(int *)a);
}

// binarySearch is a helper function to perform a binary search.
int binarySearch(int *arr, int n, int target) {
	int l = 0;
	int r = n - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (arr[m] < target) {
			l = m + 1;
		} else if (arr[m] > target) {
			r = m - 1;
		} else {
			return m;
		}
	}
	return -1;
}

// -----------------------------------------

// main function to initialize the program.
int main() {
	inputFile = fopen("input.txt", "r");
	outputFile = fopen("output.txt", "w");
	mainFn();
	fclose(inputFile);
	fclose(outputFile);
	return 0;
}

