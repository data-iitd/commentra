#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Main function is the entry point of our program
int main() {
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

// Helper functions
int max(int x, int y) {
	// Find the maximum value in the slice x
	int res = x;
	if (y > res) {
		res = y;
	}
	return res;
}

int min(int x, int y) {
	// Find the minimum value in the slice x
	int res = x;
	if (y < res) {
		res = y;
	}
	return res;
}
int pow(int x, int y) {
	// Calculate x raised to the power of y
	return (int)pow(x, y);
}
int abs(int x) {
	// Calculate the absolute value of x
	return (int)abs(x);
}
int floor(int x) {
	// Round x down to the nearest integer
	return (int)floor(x);
}

// Helper type and function for sorting a slice of integers based on their absolute values
typedef int SortBy[];

int SortBy_len(SortBy a) {
	return sizeof(a) / sizeof(int);
}

void SortBy_swap(SortBy a, int i, int j) {
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int SortBy_less(SortBy a, int i, int j) {
	return abs(a[i]) < abs(a[j]);
}

