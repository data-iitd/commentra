#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Main function: Reads input values, calculates the minimum difference, and prints the index.
int main() {
	int n, t, a; // Declare variables for n, t, and a.
	double *heights; // Declare a pointer to a double array for the heights.
	double minDiff; // Declare a variable for the minimum difference.
	int minIdx; // Declare a variable for the index of the minimum difference.

	scanf("%d %d %d", &n, &t, &a); // Read values for n, t, and a.
	heights = (double *)malloc(n * sizeof(double)); // Allocate memory for the heights.
	for (int i = 0; i < n; i++) { // Read a list of heights.
		scanf("%lf", &heights[i]);
	}

	minDiff = fabs(t - heights[0] * 0.006 - a); // Calculate the initial minimum difference.
	minIdx = 0; // Initialize the index of the minimum difference.
	for (int i = 1; i < n; i++) { // Iterate through the heights starting from the second element.
		double diff = fabs(t - heights[i] * 0.006 - a); // Calculate the difference for the current height.
		if (diff < minDiff) { // Update the minimum difference and index if a smaller difference is found.
			minDiff = diff;
			minIdx = i;
		}
	}
	printf("%d\n", minIdx + 1); // Print the index (plus one for 1-based indexing).

	free(heights); // Free the memory allocated for the heights.
	return 0;
}

