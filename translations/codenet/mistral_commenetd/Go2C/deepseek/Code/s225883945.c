#include <stdio.h>
#include <stdlib.h>

// Main function
int main() {
	// Declare variables
	int n, k, sum = 0, ans = 1;

	// Read number of elements n and the sum of elements k from the input
	scanf("%d %d", &n, &k);

	// Use a loop to find the number of times k can be subtracted from n to reach a non-negative value
	while (sum < n) {
		// Subtract 1 from sum and add k to find the next index to check
		sum = sum - 1 + k;
		// Increment the answer variable for each iteration
		ans++;
	}

	// Print the answer
	printf("%d\n", ans);

	// End of code
	return 0;
}
