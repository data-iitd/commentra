#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// min, max, asub, absなど基本関数
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

int main() {
	// Read input values
	int N, C, K;
	scanf("%d %d %d", &N, &C, &K);

	// Array to store arrival times
	int *t = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &t[i]);
	}

	// Sort the arrival times
	qsort(t, N, sizeof(int), (int (*)(const void *, const void *))&asub);

	// Initialize variables for the number of buses and passengers in the current bus
	int ans = 1;
	int cnt = 1;
	int end = t[0] + K; // Time when the bus will be full or the time window expires

	// Iterate through the sorted arrival times
	for (int i = 1; i < N; i++) {
		if (cnt < C && t[i] <= end) {
			// The current passenger can fit in the bus
			cnt++;
		} else {
			// The current bus is full or the time window has expired
			// Increment the bus count, reset the count, and update the end time
			cnt = 1;
			end = t[i] + K;
			ans++;
		}
	}

	// Output the number of buses required
	printf("%d", ans);
}

