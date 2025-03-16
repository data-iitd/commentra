#include <stdio.h>
#include <stdlib.h>

// Abs function returns the absolute value of an integer x.
int Abs(int x) {
	if (x < 0) {
		return -x; // If x is negative, return its negation.
	}
	return x; // If x is non-negative, return x itself.
}

// min function returns the smaller of two integers a and b.
int min(int a, int b) {
	if (a > b) {
		return b; // If a is greater than b, return b.
	}
	return a; // Otherwise, return a.
}

int main() {
	int N, K;
	// Read two integers N and K from standard input.
	scanf("%d %d", &N, &K);

	// The following block is commented out; it appears to be an alternative approach
	// to find a minimum value based on some conditions involving N and K.
	/*
	int hm[1000000]; // Create a map to track seen values of N.
	for (int i = 0; i < 1000000; i++) {
		hm[i] = 0;
	}
	for (int i = 0; i < 1000000; i++) {
		if (hm[N] == 0) { // If N has not been seen before,
			hm[N] = 1; // mark it as seen.
			N = Abs(N - K); // Update N to the absolute difference of N and K.
		} else {
			break; // If N has been seen, exit the loop.
		}
	}
	int mini = 999999999; // Initialize mini to a large value.
	for (int i = 0; i < 1000000; i++) {
		if (hm[i] == 1) { // Iterate over the keys in the map.
			mini = min(mini, i); // Update mini to the minimum value found.
		}
	}
	printf("%d\n", mini); // Print the minimum value found.
	*/

	int x;
	// Calculate the remainder of N divided by K.
	x = N % K;
	// Determine the minimum between the absolute difference of (x - K) and x.
	x = min(Abs(x-K), x);
	// Print the final result.
	printf("%d\n", x);

	return 0;
}
