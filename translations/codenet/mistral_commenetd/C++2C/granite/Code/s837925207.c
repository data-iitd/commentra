

#include <stdio.h>

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

