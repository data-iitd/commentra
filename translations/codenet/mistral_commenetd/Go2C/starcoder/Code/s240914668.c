#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Initialize scanner, reader, and writer
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	// Initialize answer variable
	int ans = 0;

	// Iterate through the array 'a'
	for (int i = 0; i < n; i++) {
		// Initialize left and right indices
		int l = i, r = i + 1;

		// Use a while loop to find the next index 'r' such that the difference between 'a[r]' and 'a[l]' is negative
		while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
			r++;
		}

		// Increment the answer variable
		ans++;

		// Update the index 'i' to 'r' for the next iteration
		i = r;
	}

	// Print the answer
	printf("%d", ans);
	return 0;
}

