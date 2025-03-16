
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Read the number of elements in the sequence
	int n;
	scanf("%d", &n);

	// Initialize the answer and the previous element in the sequence
	int ans = 0;
	int aPrev = 0;
	// Loop through each element in the sequence
	for (int i = 0; i < n; i++) {
		// Read the current element
		int a;
		scanf("%d", &a);
		// Check the conditions for the current element
		switch (1) {
		case a > i || a > aPrev + 1:
			// If the condition is met, print -1 and exit
			printf("-1\n");
			return 0;
		case a == aPrev + 1:
			// If the current element is one more than the previous, increment the answer
			ans++;
		default:
			// Otherwise, add the current element's value to the answer
			ans += a;
		}
		// Update the previous element to the current element
		aPrev = a;
	}
	// Print the final answer after processing all elements
	printf("%d\n", ans);
	return 0;
}

