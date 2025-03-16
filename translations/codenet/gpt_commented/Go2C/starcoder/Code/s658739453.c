

#include <stdio.h>
#include <stdlib.h>

// Define a constant for the modulo operation
#define d 1000000007

int main() {
	// Declare variables for the number of elements (n) and the number of blocked positions (p)
	int n, p;
	
	// Read the total number of elements (n) and the number of blocked positions (p) from input
	scanf("%d", &n);
	scanf("%d", &p);

	// Create a map to store the blocked positions
	int *mdans = (int *)malloc(p * sizeof(int));

	// Read the blocked positions and store them in the map
	for (int index = 0; index < p; index++) {
		int n1;
		scanf("%d", &n1);
		mdans[index] = n1;
	}

	// Initialize a slice to store the number of ways to reach each position
	int *dp = (int *)malloc((n + 1) * sizeof(int));

	// Base cases: There is 1 way to reach the 0th and 1st positions
	dp[0] = 1;
	dp[1] = 1;

	// If the first position is blocked, set the number of ways to reach it to 0
	if (mdans[0] == 1) {
		dp[1] = 0;
	}

	// Iterate through positions from 2 to n to calculate the number of ways to reach each position
	for (int i = 2; i <= n; i++) {
		// If the current position is blocked, skip the calculation
		if (mdans[i - 1] == 1) {
			continue;
		}
		// Calculate the number of ways to reach the current position using the previous two positions
		dp[i] = (dp[i - 1] + dp[i - 2]) % d;
	}

	// Print the number of ways to reach the nth position
	printf("%d\n", dp[n]);

	// Free the memory
	free(mdans);
	free(dp);
}

