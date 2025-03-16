
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the maximum of an array of integers
int max(int *a, int n) {
	int r = a[0];
	for (int i = 0; i < n; i++) {
		if (r < a[i]) {
			r = a[i];
		}
	}
	return r;
}

// Function to calculate the minimum of an array of integers
int min(int *a, int n) {
	int r = a[0];
	for (int i = 0; i < n; i++) {
		if (r > a[i]) {
			r = a[i];
		}
	}
	return r;
}

// Function to calculate the sum of an array of integers
int sum(int *a, int n) {
	int r = 0;
	for (int i = 0; i < n; i++) {
		r += a[i];
	}
	return r;
}

// Function to calculate the absolute difference of two integers
int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// Function to read input from standard input as a single string
char *nextReader() {
	char *r = malloc(1024 * sizeof(char));
	fgets(r, 1024, stdin);
	r[strcspn(r, "\n")] = 0;
	return r;
}

// Function to read a single string from standard input
char *nextString() {
	return nextReader();
}

// Function to read a single integer from standard input
int nextInt() {
	char *r = nextReader();
	int v;
	sscanf(r, "%d", &v);
	return v;
}

// Function to read an array of N integers from standard input
int *nextInts(int n) {
	int *r = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		r[i] = nextInt();
	}
	return r;
}

// Function to calculate the minimum number of jumps required to reach the last index of an array of integers
int minJumps(int *h, int n) {
	// Initialize a dp array of size N with zeros
	int *dp = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		dp[i] = 0;
	}

	// Set the first element of dp to the absolute difference between the first and second elements of h
	dp[1] = abs(h[0] - h[1]);

	// Iterate over the array h from the second element to the last
	for (int i = 2; i < n; i++) {
		// Set the current element of dp to the minimum of the previous and previous-previous elements plus the absolute difference between the current and previous/previous elements
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
	}

	// Return the last element of dp, which is the minimum number of jumps required to reach the last index of h
	return dp[n - 1];
}

// Main function is the entry point of the program
int main() {
	// Read the number of test cases N from standard input
	int N = nextInt();

	// Read an array h of N integers from standard input
	int *h = nextInts(N);

	// Calculate the minimum number of jumps required to reach the last index of h
	int minJumps = minJumps(h, N);

	// Print the minimum number of jumps required to reach the last index of h
	printf("%d\n", minJumps);

	// Free the memory allocated for the array h
	free(h);

	// Free the memory allocated for the array dp
	free(dp);

	return 0;
}

