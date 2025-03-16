#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Initialize arrays h and w of size 6
int h[6], w[6];

int main() {
	int x, ans = 0; // Initialize x and ans to zero

	// Read input value of x from the user
	scanf("%d", &x);

	// Calculate the answer using the given formula
	ans = x + x*x + x*x*x;

	// Output the answer to the user
	printf("%d\n", ans);

	return 0;
}

