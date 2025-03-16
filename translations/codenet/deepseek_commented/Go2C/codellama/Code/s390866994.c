#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sort the arrival times
void sort(int *t, int N) {
	int i, j, temp;
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (t[i] > t[j]) {
				temp = t[i];
				t[i] = t[j];
				t[j] = temp;
			}
		}
	}
}

int main() {
	int N, C, K, i, ans, cnt, end;
	int *t;

	// Read input values
	scanf("%d", &N); // Number of passengers
	scanf("%d", &C); // Bus capacity
	scanf("%d", &K); // Time window

	// Array to store arrival times
	t = (int *)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) {
		scanf("%d", &t[i]);
	}

	// Sort the arrival times
	sort(t, N);

	// Initialize variables for the number of buses and passengers in the current bus
	ans = 1;
	cnt = 1;
	end = t[0] + K; // Time when the bus will be full or the time window expires

	// Iterate through the sorted arrival times
	for (i = 1; i < N; i++) {
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
	printf("%d\n", ans);

	// Free memory
	free(t);

	return 0;
}

