

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Define a struct to represent an arm with left and right bounds
typedef struct {
	int l, r;
} arm;

// Function to read an integer from input
int scanInt() {
	int x;
	scanf("%d", &x);
	return x;
}

// Function to sort arms based on their right bounds
int cmp(const void *a, const void *b) {
	return ((arm*)a)->r - ((arm*)b)->r;
}

// Main function where the program execution begins
int main() {
	// Read the number of arms
	int n = scanInt();
	
	// Allocate memory for the arms
	arm *as = (arm*)malloc(n * sizeof(arm));
	
	// Read the arm data from input
	for (int i = 0; i < n; i++) {
		int x, l = scanInt();
		as[i].l = x - l;
		as[i].r = x + l;
	}
	
	// Sort the arms based on their right bounds
	qsort(as, n, sizeof(arm), cmp);
	
	// Initialize the count of non-overlapping arms and the rightmost bound
	int ans = 1;
	int r = as[0].r;
	
	// Iterate through the sorted arms to count non-overlapping arms
	for (int i = 1; i < n; i++) {
		// If the left bound of the current arm is greater than or equal to the rightmost bound
		if (as[i].l >= r) {
			ans++; // Increment the count of non-overlapping arms
			r = as[i].r; // Update the rightmost bound to the current arm's right bound
		}
	}
	
	// Print the total count of non-overlapping arms
	printf("%d\n", ans);
}

