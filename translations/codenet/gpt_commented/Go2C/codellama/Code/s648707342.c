#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan an integer from input
int scanInt() {
	char str[100];
	int iv;
	scanf("%s", str);
	iv = atoi(str);
	return iv;
}

// Initialize the scanner to split input by whitespace
void init() {
	scanf("%s", str);
}

// Main function where the program execution begins
int main() {
	// Read the number of arms
	int n = scanInt();
	
	// Define a struct to represent an arm with left and right bounds
	struct arm {
		int l;
		int r;
	};
	
	// Create a slice to hold the arms
	struct arm *as = (struct arm *)malloc(n * sizeof(struct arm));
	
	// Read the arm data from input
	for (int i = 0; i < n; i++) {
		int x, l;
		x = scanInt(); // Read the center and length of the arm
		l = scanInt();
		as[i].l = x - l; // Calculate the left bound
		as[i].r = x + l; // Calculate the right bound
	}
	
	// Sort the arms based on their right bounds
	qsort(as, n, sizeof(struct arm), compare);

	// Initialize the count of non-overlapping arms and the rightmost bound
	int ans = 1; // Start with the first arm
	int r = as[0].r; // Set the rightmost bound to the right of the first arm
	
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
	
	return 0;
}

int compare(const void *a, const void *b) {
	return ((struct arm *)a)->r - ((struct arm *)b)->r;
}

