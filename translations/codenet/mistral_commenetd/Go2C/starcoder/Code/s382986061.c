#include <stdio.h>
#include <stdlib.h>

// Initialize variables
int N, K;
int d, a;

int main() {
	// Read input values for N and K
	scanf("%d %d", &N, &K);

	// Initialize an associative array (map) named as to store the frequency of each number
	int *as = (int *)malloc(sizeof(int) * (N + 1));

	// Initialize all elements of the map with zero frequency
	for (int i = 1; i <= N; i++) {
		as[i] = 0;
	}

	// Read K queries and process them
	for (int i = 0; i < K; i++) {
		// Read the length of the query
		scanf("%d", &d);

		// Read the numbers in the query and increment their frequency in the map
		for (int j = 0; j < d; j++) {
			scanf("%d", &a);
			as[a]++;
		}
	}

	// Initialize a variable named ans to store the answer
	int ans = 0;

	// Iterate through the map and check if the frequency of any number is zero
	// If yes, increment the value of ans
	for (int i = 1; i <= N; i++) {
		if (as[i] == 0) {
			ans++;
		}
	}

	// Print the final answer
	printf("%d", ans);

	// End of the code
}

