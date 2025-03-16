#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Read the number of elements N and the threshold K
int N, K;
scanf("%d %d", &N, &K);

// Read the two slices of integers As and Fs
int *As = malloc(N * sizeof(int));
int *Fs = malloc(N * sizeof(int));
for (int i = 0; i < N; i++) {
	scanf("%d", &As[i]);
}
for (int i = 0; i < N; i++) {
	scanf("%d", &Fs[i]);
}

// Sort the As slice in ascending order
qsort(As, N, sizeof(int), compare_asc);

// Sort the Fs slice in descending order
qsort(Fs, N, sizeof(int), compare_desc);

// Create a slice to hold the scores calculated from As and Fs
int *scores = malloc(N * sizeof(int));
for (int i = 0; i < N; i++) {
	// Calculate the score for each pair of As and Fs
	scores[i] = As[i] * Fs[i];
}

// Sort the scores in descending order
qsort(scores, N, sizeof(int), compare_desc);

// Initialize binary search boundaries
int ok = scores[0]; // The maximum possible score
int ng = -1;        // The minimum possible score

// Perform binary search to find the maximum score that can be achieved
while (ok - ng > 1) {
	int mid = (ok + ng) / 2; // Calculate the midpoint of the current range

	int isOK = 1; // Flag to check if the current mid is achievable
	int k = K;    // Remaining threshold to adjust scores
	for (int i = 0; isOK && i < N; i++) {
		// If the current score exceeds mid, calculate how much we need to reduce
		if (As[i] * Fs[i] > mid) {
			k -= As[i] - mid / Fs[i];
		}
		// If we exceed the allowed threshold, mark isOK as false
		if (k < 0) {
			isOK = 0;
		}
	}

	// Adjust binary search boundaries based on whether mid is achievable
	if (isOK) {
		ok = mid; // If achievable, move the upper boundary
	} else {
		ng = mid; // If not achievable, move the lower boundary
	}
}

// Print the maximum achievable score
printf("%d\n", ok);

// Free memory
free(As);
free(Fs);
free(scores);

// 