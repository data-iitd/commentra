#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Helper functions
int max(int x, int y) {
	// Find the maximum value in the slice x
	return (x > y)? x : y;
}

int min(int x, int y) {
	// Find the minimum value in the slice x
	return (x < y)? x : y;
}

int pow(int x, int y) {
	// Calculate x raised to the power of y
	return (int) pow(x, y);
}

int abs(int x) {
	// Calculate the absolute value of x
	return (x < 0)? -x : x;
}

int floor(int x) {
	// Round x down to the nearest integer
	return (int) floor(x);
}

// Helper type and function for sorting a slice of integers based on their absolute values
typedef struct {
	int size;
	int *data;
} SortBy;

int sort_by_abs_cmp(const void *a, const void *b) {
	// Compare the absolute values of a and b
	int x = *(int *) a;
	int y = *(int *) b;
	return abs(x) - abs(y);
}

int sort_by_abs(SortBy *a) {
	// Sort the slice a based on the absolute values of its elements
	qsort(a->data, a->size, sizeof(int), sort_by_abs_cmp);
}

// Main function is the entry point of our program
int main(int argc, char *argv[]) {
	// Declare and initialize variables
	int N, M, ans;

	// Read N and M from the standard input
	scanf("%d %d", &N, &M);

	// Check if N and M are equal to 1
	if (N == 1 && M == 1) {
		// If so, increment the ans variable
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If N and M are greater than 1, calculate the area of the rectangle
		ans += (N - 2) * (M - 2);
	} else {
		// If N or M is equal to 1, calculate the number of points on the edge
		ans += (N * M) - 2;
	}

	// Print the value of ans to the standard output
	printf("%d\n", ans);
	return 0;
}

