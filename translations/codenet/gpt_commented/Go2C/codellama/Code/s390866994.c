#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print output to the console
void out(int x) {
	printf("%d\n", x);
}

// Function to read an integer from input
int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function to read a string from input
char* getString() {
	char* s = malloc(100 * sizeof(char));
	scanf("%s", s);
	return s;
}

// Basic utility functions for mathematical operations
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
	// Read the number of elements (N), maximum count (C), and time limit (K)
	int N, C, K;
	N = getInt();
	C = getInt();
	K = getInt();
	int* t = malloc(N * sizeof(int)); // Create a slice to hold the time values

	// Read N time values from input
	for (int i = 0; i < N; i++) {
		t[i] = getInt(); // Store each time value in the slice
	}

	// Sort the time values in ascending order
	qsort(t, N, sizeof(int), compare);

	// Initialize variables for counting groups and tracking the end time
	int ans = 1; // Start with one group
	int cnt = 1; // Count of elements in the current group
	int end = t[0] + K; // Calculate the end time for the first group

	// Iterate through the sorted time values
	for (int i = 1; i < N; i++) {
		// Check if we can add the current time to the current group
		if (cnt < C && t[i] <= end) {
			cnt++; // Increment the count of the current group
		} else {
			// Start a new group since the current time exceeds the end time
			cnt = 1; // Reset the count for the new group
			end = t[i] + K; // Update the end time for the new group
			ans++; // Increment the group count
		}
	}
	out(ans); // Output the total number of groups formed
	return 0;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

