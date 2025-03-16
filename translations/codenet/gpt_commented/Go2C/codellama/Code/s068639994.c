
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// mainFn contains the core logic of the program
void mainFn() {
	// Read the number of elements
	int n = getInt();
	// Read the integer slice from input
	int *ls = getIntSlice(n);
	// Create a reversed copy of the original slice
	int *lsRev = (int *)malloc(n * sizeof(int));
	memcpy(lsRev, ls, n * sizeof(int));
	// Sort the original slice in ascending order
	sortInts(ls, n);
	// Sort the reversed slice in descending order
	sortIntsRev(lsRev, n);

	// Initialize the answer variable
	int ans = 0;
	// Iterate through all pairs of elements in the sorted slice
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// Determine the minimum and maximum of the two selected elements
			int p, q;
			if (ls[i] < ls[j]) {
				p = ls[i];
				q = ls[j];
			} else {
				p = ls[j];
				q = ls[i];
			}
			// Calculate the differences and sums needed for searching
			int x = q - p;
			int y = q + p;

			// Find the left boundary for elements greater than x
			int l = findLeft(ls, n, x);
			// Find the right boundary for elements less than y
			int r = findRight(lsRev, n, y);

			// Calculate the number of valid elements in the range
			int sum = r - l;
			// Adjust the count if the current indices are within the range
			if ((i >= l) && (i <= r)) {
				sum--;
			}
			if ((j >= l) && (j <= r)) {
				sum--;
			}
			// Ensure the sum is non-negative
			sum = max(0, sum);
			// Accumulate the result
			ans += sum;
		}
	}

	// Divide the final answer by 3 as per the problem requirements
	ans /= 3;
	// Output the result
	puts(ans);
}

// sortInts sorts the given integer slice in ascending order
void sortInts(int *ls, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ls[i] > ls[j]) {
				int tmp = ls[i];
				ls[i] = ls[j];
				ls[j] = tmp;
			}
		}
	}
}

// sortIntsRev sorts the given integer slice in descending order
void sortIntsRev(int *ls, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ls[i] < ls[j]) {
				int tmp = ls[i];
				ls[i] = ls[j];
				ls[j] = tmp;
			}
		}
	}
}

// findLeft finds the left boundary for elements greater than the given value
int findLeft(int *ls, int n, int x) {
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (ls[m] > x) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	return l;
}

// findRight finds the right boundary for elements less than the given value
int findRight(int *ls, int n, int y) {
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (ls[m] < y) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	return l;
}

// max returns the larger of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// getInt reads an integer from input
int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// getIntSlice reads a slice of integers from input
int *getIntSlice(int n) {
	int *is = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &is[i]);
	}
	return is;
}

// puts writes the given arguments to the output
void puts(int a) {
	printf("%d\n", a);
}

// 