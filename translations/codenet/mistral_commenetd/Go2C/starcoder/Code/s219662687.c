#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_N 100000
#define INF 1000000000000

// Function declaration
int min(int x, int y) {
	return x < y? x : y;
}

int max(int x, int y) {
	return x > y? x : y;
}

int abs(int x) {
	return x < 0? -x : x;
}

int main() {
	// Reading input values from standard input
	int A = nextInt();
	int B = nextInt();
	int Q = nextInt();

	// Initializing arrays s and t with size A+2 and B+2 respectively
	// The first and last elements are initialized with -INF and INF respectively
	int s[MAX_N+2];
	memset(s, 0, sizeof(s));
	s[0] = -INF;
	s[A+1] = INF;

	// Reading A elements of array s from standard input
	for (int i = 1; i <= A; i++) {
		s[i] = nextInt();
	}

	// Initializing array t with size B+2
	// The first and last elements are initialized with -INF and INF respectively
	int t[MAX_N+2];
	memset(t, 0, sizeof(t));
	t[0] = -INF;
	t[B+1] = INF;

	// Reading B elements of array t from standard input
	for (int i = 1; i <= B; i++) {
		t[i] = nextInt();
	}

	// Processing each query
	for (int i = 0; i < Q; i++) {
		// Reading query value x from standard input
		int x = nextInt();

		// Finding the indices b and d of array s and t respectively
		// where s[b] and t[d] are the smallest elements greater than x
		int b = 0, d = 0;
		while (b < A+2 && s[b] <= x) {
			b++;
		}
		while (d < B+2 && t[d] <= x) {
			d++;
		}

		// Computing the minimum distance between x and any pair of elements S and T
		// from arrays s and t respectively
		int res = INF;
		for (int S = s[b-1]; S <= s[b]; S++) {
			for (int T = t[d-1]; T <= t[d]; T++) {
				// Computing the absolute difference between S and x, and T and S
				int d1 = abs(S-x);
				int d2 = abs(T-S);

				// Updating the minimum distance if the current pair has a smaller distance
				res = min(res, min(d1, d2));
			}
		}

		// Printing the minimum distance for the current query
		printf("%d\n", res);
	}
}

// Input reading helper functions
int nextInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// 