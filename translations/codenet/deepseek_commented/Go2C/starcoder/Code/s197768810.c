#include <stdio.h>
#include <stdlib.h>

int main() {
	// Read two integers n and m from the input
	int n = readInt();
	int m = readInt();

	// Initialize a slice to hold m integers
	int a[m];
	int sum = 0;

	// Read m integers into the slice a and calculate their sum
	for (int i = 0; i < m; i++) {
		a[i] = readInt();
		sum += a[i];
	}

	// Check if the sum of integers exceeds n
	if (sum > n) {
		// Print -1 if the sum exceeds n and exit
		printf("-1\n");
		return;
	}

	// Print the difference between n and the sum if it's within bounds
	printf("%d\n", n - sum);
}

// readInt reads a single integer from the standard input
int readInt() {
	int n;
	scanf("%d", &n);
	return n;
}

