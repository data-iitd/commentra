
#include <stdio.h>
#include <stdlib.h>

#define d 1000000007

int main() {
	int n, p;
	scanf("%d", &n); // Read the value of n from standard input
	scanf("%d", &p); // Read the value of p from standard input

	int *mdans = (int *)malloc(p * sizeof(int));
	for (int index = 0; index < p; index++) {
		int n1;
		scanf("%d", &n1); // Read each value into the map mdans
		mdans[index] = n1;
	}

	int *dp = (int *)malloc((n + 1) * sizeof(int));
	dp[0] = 1; // Initialize the first element of dp slice
	dp[1] = 1; // Initialize the second element of dp slice

	if (mdans[0] == 1) { // Check if the value 1 is in the map mdans
		dp[1] = 0; // Set dp[1] to 0 if 1 is in the map
	}

	for (int i = 2; i <= n; i++) {
		if (mdans[i - 1] == 1) { // Check if the current value i is in the map mdans
			continue; // Skip to the next iteration if i is in the map
		}
		dp[i] = (dp[i - 1] + dp[i - 2]) % d; // Calculate dp[i] as the sum of dp[i-1] and dp[i-2], modulo d
	}

	printf("%d\n", dp[n]); // Print the value at dp[n]
	free(mdans);
	free(dp);
	return 0;
}

