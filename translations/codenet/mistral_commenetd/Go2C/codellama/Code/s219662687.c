
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// Package declaration and importing necessary packages
int main() {
	const int INF = 1000000000; // Large constant value for initializing arrays

	// Reading input values from standard input
	int A = 0, B = 0, Q = 0;
	scanf("%d %d %d", &A, &B, &Q);

	// Initializing arrays s and t with size A+2 and B+2 respectively
	// The first and last elements are initialized with -INF and INF respectively
	int s[A+2];
	s[0], s[A+1] = -INF, INF;

	// Reading A elements of array s from standard input
	for (int i = 1; i <= A; i++) {
		scanf("%d", &s[i]);
	}

	// Initializing array t with size B+2
	// The first and last elements are initialized with -INF and INF respectively
	int t[B+2];
	t[0], t[B+1] = -INF, INF;

	// Reading B elements of array t from standard input
	for (int i = 1; i <= B; i++) {
		scanf("%d", &t[i]);
	}

	// Processing each query
	for (int i = 0; i < Q; i++) {
		// Reading query value x from standard input
		int x = 0;
		scanf("%d", &x);

		// Finding the indices b and d of array s and t respectively
		// where s[b] and t[d] are the smallest elements greater than x
		int b = 0, d = 0;
		for (int j = 1; j <= A; j++) {
			if (s[j] > x) {
				b = j;
				break;
			}
		}
		for (int j = 1; j <= B; j++) {
			if (t[j] > x) {
				d = j;
				break;
			}
		}

		// Computing the minimum distance between x and any pair of elements S and T
		// from arrays s and t respectively
		int res = INF;
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				// Computing the absolute difference between S and x, and T and S
				int d1 = abs(s[b-1+j]-x), d2 = abs(t[d-1+k]-s[b-1+j]);

				// Updating the minimum distance if the current pair has a smaller distance
				res = min(res, min(d1, d2));
			}
		}

		// Printing the minimum distance for the current query
		printf("%d\n", res);
	}

	return 0;
}

int min(int x, int y) {
	return x < y ? x : y;
}

int abs(int x) {
	return x < 0 ? -x : x;
}

