

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

// max returns the larger of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// min returns the smaller of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// mainFn contains the core logic of the program
void mainFn() {
	// Read the number of elements
	int n = getInt();
	// Read the integer slice from input
	int *ls = getIntSlice(n);
	// Create a reversed copy of the original slice
	int *lsRev = malloc(n * sizeof(int));
	memcpy(lsRev, ls, n * sizeof(int));
	// Sort the original slice in ascending order
	qsort(ls, n, sizeof(int), NULL);
	// Sort the reversed slice in descending order
	qsort(lsRev, n, sizeof(int), NULL);

	// Initialize the answer variable
	int ans = 0;
	// Iterate through all pairs of elements in the sorted slice
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// Determine the minimum and maximum of the two selected elements
			int p = min(ls[i], ls[j]);
			int q = max(ls[i], ls[j]);
			// Calculate the differences and sums needed for searching
			int x = q - p;
			int y = q + p;

			// Find the left boundary for elements greater than x
			int l = 0;
			while (l < n && ls[l] <= x) {
				l++;
			}
			// Find the right boundary for elements less than y
			int r = n - 1;
			while (r >= 0 && lsRev[r] >= y) {
				r--;
			}

			// Calculate the number of valid elements in the range
			int sum = r - l;
			// Adjust the count if the current indices are within the range
			if (i >= l) && (i <= r) {
				sum--;
			}
			if (j >= l) && (j <= r) {
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

// getInt reads an integer from input
int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// getIntSlice reads a slice of integers from input
int *getIntSlice(int n) {
	int *is = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		is[i] = getInt();
	}
	return is;
}

// getString reads a string from input
char *getString() {
	char *s = malloc(100000 * sizeof(char));
	scanf("%s", s);
	return s;
}

// puts writes the given arguments to the output
void puts(int n,...) {
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", va_arg(args, int));
	}
	printf("\n");
	va_end(args);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

// max returns the larger of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// min returns the smaller of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// mainFn contains the core logic of the program
void mainFn() {
	// Read the number of elements
	int n = getInt();
	// Read the integer slice from input
	int *ls = getIntSlice(n);
	// Create a reversed copy of the original slice
	int *lsRev = malloc(n * sizeof(int));
	memcpy(lsRev, ls, n * sizeof(int));
	// Sort the original slice in ascending order
	qsort(ls, n, sizeof(int), NULL);
	// Sort the reversed slice in descending order
	qsort(lsRev, n, sizeof(int), NULL);

	// Initialize the answer variable
	int ans = 0;
	// Iterate through all pairs of elements in the sorted slice
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// Determine the minimum and maximum of the two selected elements
			int p = min(ls[i], ls[j]);
			int q = max(ls[i], ls[j]);
			// Calculate the differences and sums needed for searching
			int x = q - p;
			int y = q + p;

			// Find the left boundary for elements greater than x
			int l = 0;
			while (l < n && ls[l] <= x) {
				l++;
			}
			// Find the right boundary for elements less than y
			int r = n - 1;
			while (r >= 0 && lsRev[r] >= y) {
				r--;
			}

			// Calculate the number of valid elements in the range
			int sum = r - l;
			// Adjust the count if the current indices are within the range
			if (i >= l) && (i <= r) {
				sum--;
			}
			if (j >= l) && (j <= r) {
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

// getInt reads an integer from input
int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// getIntSlice reads a slice of integers from input
int *getIntSlice(int n) {
	int *is = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		is[i] = getInt();
	}
	return is;
}

// getString reads a string from input
char *getString() {
	char *s = malloc(100000 * sizeof(char));
	scanf("%s", s);
	return s;
}

// puts writes the given arguments to the output
void puts(int n,...) {
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", va_arg(args, int));
	}
	printf("\n");
	va_end(args);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

// max returns the larger of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// min returns the smaller of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// mainFn contains the core logic of the program
void mainFn() {
	// Read the number of elements
	int n = getInt();
	// Read the integer slice from input
	int *ls = getIntSlice(n);
	// Create a reversed copy of the original slice
	int *lsRev = malloc(n * sizeof(int));
	memcpy(lsRev, ls, n * sizeof(int));
	// Sort the original slice in ascending order
	qsort(ls, n, sizeof(int), NULL);
	// Sort the reversed slice in descending order
	qsort(lsRev, n, sizeof(int), NULL);

	// Initialize the answer variable
	int ans = 0;
	// Iterate through all pairs of elements in the sorted slice
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// Determine the minimum and maximum of the two selected elements
			int p = min(ls[i], ls[j]);
			int q = max(ls[i], ls[j]);
			// Calculate the differences and sums needed for searching
			int x = q - p;
			int y = q + p;

			// Find the left boundary for elements greater than x
			int l = 0;
			while (l < n && ls[l] <= x) {
				l++;
			}
			// Find the right boundary for elements less than y
			int r = n - 1;
			while (r >= 0 && lsRev[r] >= y) {
				r--;
			}

			// Calculate the number of valid elements in the range
			int sum = r - l;
			// Adjust the count if the current indices are within the range
			if (i >= l) && (i <= r) {
				sum--;
			}
			if (j >= l) && (j <= r) {
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

// getInt reads an integer from input
int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// getIntSlice reads a slice of integers from input
int *getIntSlice(int n) {
	int *is = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		is[i] = getInt();
	}
	return is;
}

// getString reads a string from input
char *getString() {
	char *s = malloc(100000 * sizeof(char));
	scanf("%s", s);
	return s;
}

// puts writes the given arguments to the output
void puts(int n,...) {
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", va_arg(args, int));
	}
	printf("\n");
	va_end(args);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

// max returns the larger of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// min returns the smaller of two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// mainFn contains the core logic of the program
void mainFn() {
	// Read the number of elements
	int n = getInt();
	// Read the integer slice from input
	int *ls = getIntSlice(n);
	// Create a reversed copy of the original slice
	int *lsRev = malloc(n * sizeof(int));
	memcpy(lsRev, ls, n * sizeof(int));
	// Sort the original slice in ascending order
	qsort(ls, n, sizeof(int), NULL);
	// Sort the reversed slice in descending order
	qsort(lsRev, n, sizeof(int), NULL);

	// Initialize the answer variable
	int ans = 0;
	// Iterate through all pairs of elements in the sorted slice
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// Determine the minimum and maximum of the two selected elements
			int p = min(ls[i], ls[j]);
			int q = max(ls[i], ls[j]);
			// Calculate the differences and sums needed for searching
			int x = q - p;
			int y = q + p;

			// Find the left boundary for elements greater than x
			int l = 0;
			while (l < n && ls[l] <= x) {
				l++;
			}
			// Find the right boundary for elements less than y
			int r = n - 1;
			while (r >= 0 && lsRev[r] >= y) {
				r--;
			}

			// Calculate the number of valid elements in the range
			int sum = r - l;
			// Adjust the count if the current indices are within the range
			if (i >= l) && (i <= r) {
				sum--;
			}
			if (j >= l) && (j <= r) {
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

// getInt reads an integer from input
int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// getIntSlice reads a slice of integers from input
int *getIntSlice(int n) {
	int *is = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		is[i] = getInt();
	}
	return is;
}

// getString reads a string from input
char *getString() {
	char *s = malloc(100000 * sizeof(char));
	scanf("%s", s);
	return s;
}

// puts writes the given arguments to the output
void pu