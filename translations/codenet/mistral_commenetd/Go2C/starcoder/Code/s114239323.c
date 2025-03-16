#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to read input from standard input as a single string
char* nextString() {
	char *s = malloc(1024);
	scanf("%s", s);
	return s;
}

// Helper function to read a single integer from standard input
int nextInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Helper function to read an array of N integers from standard input
int* nextInts(int n) {
	int *r = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &r[i]);
	}
	return r;
}

// Helper functions to calculate the maximum, minimum, sum, and absolute difference of integers
int Max(int a[], int n) {
	int r = a[0];
	for (int i = 0; i < n; i++) {
		if (r < a[i]) {
			r = a[i];
		}
	}
	return r;
}

int Min(int a[], int n) {
	int r = a[0];
	for (int i = 0; i < n; i++) {
		if (r > a[i]) {
			r = a[i];
		}
	}
	return r;
}

int Sum(int a[], int n) {
	int r = 0;
	for (int i = 0; i < n; i++) {
		r += a[i];
	}
	return r;
}

int Abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

int main() {
	// Read the number of test cases N from standard input
	int N = nextInt();

	// Read an array h of N integers from standard input
	int *h = nextInts(N);

	// Initialize a dp array of size N with zeros
	int *dp = malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		dp[i] = 0;
	}

	// Set the first element of dp to the absolute difference between the first and second elements of h
	dp[1] = Abs(h[0] - h[1]);

	// Iterate over the array h from the second element to the last
	for (int i = 2; i < N; i++) {
		// Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
		dp[i] = Min(dp[i - 1] + Abs(h[i] - h[i - 1]), dp[i - 2] + Abs(h[i] - h[i - 2]));
	}

	// Print the last element of dp, which is the minimum number of jumps required to reach the last index of h
	printf("%d\n", dp[N - 1]);
}

