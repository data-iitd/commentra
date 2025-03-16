#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MAX_N 100000
#define MAX_K 100000

int N, K;
int As[MAX_N];
int Fs[MAX_N];
int scores[MAX_N];

int main() {
	// Read the number of elements N and the maximum number of operations K
	scanf("%d %d", &N, &K);
	
	// Read the list of integers As
	for (int i = 0; i < N; i++) {
		scanf("%d", &As[i]);
	}
	
	// Read the list of integers Fs
	for (int i = 0; i < N; i++) {
		scanf("%d", &Fs[i]);
	}
	
	// Sort As in ascending order
	qsort(As, N, sizeof(int), cmpint);
	
	// Sort Fs in descending order
	qsort(Fs, N, sizeof(int), cmpint_rev);
	
	// Calculate the scores by multiplying corresponding elements of As and Fs
	for (int i = 0; i < N; i++) {
		scores[i] = As[i] * Fs[i];
	}
	
	// Sort the scores in descending order to prepare for binary search
	qsort(scores, N, sizeof(int), cmpint_rev);
	
	// Initialize the boundaries for binary search
	int ok = scores[0];
	int ng = -1;
	
	// Perform binary search to find the maximum score
	while (ok - ng > 1) {
		int mid = (ok + ng) / 2;
		
		// Check if it's possible to achieve mid score with at most K operations
		bool isOK = true;
		int k = K;
		for (int i = 0; isOK && i < N; i++) {
			if (As[i] * Fs[i] > mid) {
				k -= As[i] - mid / Fs[i];
			}
			if (k < 0) {
				isOK = false;
			}
		}
		
		// Adjust the search boundaries based on the result of the check
		if (isOK) {
			ok = mid;
		} else {
			ng = mid;
		}
	}
	
	// Print the maximum score found
	printf("%d\n", ok);
}

// cmpint is a comparator function for integers
int cmpint(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

// cmpint_rev is a comparator function for integers in reverse order
int cmpint_rev(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

