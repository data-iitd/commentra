#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Read the number of elements N and the maximum number of operations K
int N, K;

// Read the list of integers As
int *As;

// Read the list of integers Fs
int *Fs;

// Sort As in ascending order
void sort_As(int *As, int N) {
	int i, j, t;
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (As[i] > As[j]) {
				t = As[i];
				As[i] = As[j];
				As[j] = t;
			}
		}
	}
}

// Sort Fs in descending order
void sort_Fs(int *Fs, int N) {
	int i, j, t;
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (Fs[i] < Fs[j]) {
				t = Fs[i];
				Fs[i] = Fs[j];
				Fs[j] = t;
			}
		}
	}
}

// Create a list to store the scores
int *scores;

// Calculate the scores by multiplying corresponding elements of As and Fs
void calculate_scores(int *As, int *Fs, int N) {
	int i;
	scores = (int *)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) {
		scores[i] = As[i] * Fs[i];
	}
}

// Sort the scores in descending order to prepare for binary search
void sort_scores(int *scores, int N) {
	int i, j, t;
	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (scores[i] < scores[j]) {
				t = scores[i];
				scores[i] = scores[j];
				scores[j] = t;
			}
		}
	}
}

// Initialize the boundaries for binary search
int ok, ng;

// Perform binary search to find the maximum score
void binary_search(int *scores, int N) {
	ok = scores[0];
	ng = -1;
	while (ok - ng > 1) {
		int mid = (ok + ng) / 2;
		int k = K;
		int i;
		for (i = 0; i < N; i++) {
			if (As[i] * Fs[i] > mid) {
				k -= As[i] - mid / Fs[i];
			}
			if (k < 0) {
				break;
			}
		}
		if (i == N) {
			ok = mid;
		} else {
			ng = mid;
		}
	}
}

// Print the maximum score found
void print_result(int ok) {
	printf("%d\n", ok);
}

int main() {
	// Read the number of elements N and the maximum number of operations K
	scanf("%d %d", &N, &K);
	
	// Read the list of integers As
	As = (int *)malloc(N * sizeof(int));
	int i;
	for (i = 0; i < N; i++) {
		scanf("%d", &As[i]);
	}
	
	// Read the list of integers Fs
	Fs = (int *)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) {
		scanf("%d", &Fs[i]);
	}
	
	// Sort As in ascending order
	sort_As(As, N);
	
	// Sort Fs in descending order
	sort_Fs(Fs, N);
	
	// Calculate the scores by multiplying corresponding elements of As and Fs
	calculate_scores(As, Fs, N);
	
	// Sort the scores in descending order to prepare for binary search
	sort_scores(scores, N);
	
	// Perform binary search to find the maximum score
	binary_search(scores, N);
	
	// Print the maximum score found
	print_result(ok);
	
	// Free the memory allocated for As, Fs, and scores
	free(As);
	free(Fs);
	free(scores);
	
	return 0;
}

