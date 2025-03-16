
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize scanner
char sc[1000000];
int sc_i = 0;

// Function to read an integer from standard input
int scanInt() {
	// Scan the next token
	while (sc[sc_i] != ' ' && sc[sc_i] != '\0') {
		sc_i++;
	}
	sc[sc_i] = '\0';
	int iv = atoi(sc); // Convert the token to integer
	return iv; // Return the integer
}

// Main function
int main() {
	// Read the number of arms, n
	int n = scanInt();

	// Initialize a slice of arm structures, as
	struct arm {
		int l;
		int r;
	};
	struct arm *as = (struct arm *)malloc(n * sizeof(struct arm));

	// Read and initialize each arm structure in the slice
	for (int i = 0; i < n; i++) {
		// Read the position and length of the arm
		int x = scanInt();
		int l = scanInt();

		// Initialize the left and right fields of the arm structure
		as[i].l = x - l;
		as[i].r = x + l;
	}

	// Sort the slice based on the right field of the arm structures
	qsort(as, n, sizeof(struct arm), cmp);

	// Initialize answer variable, ans, and right variable, r
	int ans = 1;
	int r = as[0].r;

	// Iterate through the slice and update the answer and right variable accordingly
	for (int i = 1; i < n; i++) {
		if (as[i].l >= r) { // Check if the left end of the current arm is greater than or equal to the right end of the previous arm
			ans++; // Increment the answer if it is
			r = as[i].r; // Update the right variable with the right end of the current arm
		}
	}

	// Print the answer
	printf("%d\n", ans);

	// End of code
	return 0;
}

// Function to compare the right field of two arm structures
int cmp(const void *a, const void *b) {
	return ((struct arm *)a)->r - ((struct arm *)b)->r;
}

