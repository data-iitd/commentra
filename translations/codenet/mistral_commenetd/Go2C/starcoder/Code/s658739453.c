
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define d 1000000007

int main() {
	// Initialize variables
	int n, p;

	scanf("%d", &n); // Read the first integer 'n' from the standard input
	scanf("%d", &p); // Read the second integer 'p' from the standard input

	int *mdans = (int *) malloc(p * sizeof(int)); // Initialize an array'mdans' of size 'p'

	// Read 'p' distinct numbers from the standard input and store them in the array'mdans'
	for (int index = 0; index < p; index++) {
		int n1;
		scanf("%d", &n1);
		mdans[index] = n1; // Store the number 'n1' in the array'mdans' at the current index
	}

	int *dp = (int *) malloc((n + 1) * sizeof(int)); // Initialize an array 'dp' of size 'n+1'

	dp[0] = 1; // Initialize the first element of the array 'dp' with a value of '1'
	dp[1] = 1; // Initialize the second element of the array 'dp' with a value of '1'

	// Initialize the third element of the array 'dp' with a value of '0' if the number '1' is present in the array'mdans'
	if (mdans[0] == 1) {
		dp[1] = 0;
	}

	// Calculate the remaining elements of the array 'dp' using the previous elements
	for (int i = 2; i <= n; i++) {
		if (mdans[i - 1] == 1) {
			continue; // Skip the current iteration if the number 'i' is present in the array'mdans'
		}
		dp[i] = (dp[i - 1] + dp[i - 2]) % d; // Calculate the current element of the array 'dp' as the sum of the previous two elements modulo 'd'
	}

	// Print the final result
	printf("%d\n", dp[n]); // Print the value of the last element of the array 'dp'

	free(mdans);
	free(dp);

	return 0;
}

