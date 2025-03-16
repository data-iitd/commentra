#include <stdio.h>
#include <stdlib.h>

int main() {
	// Read the first three integers as input
	int r, D, x;
	scanf("%d %d %d", &r, &D, &x);

	// Iterate through a loop 10 times
	for (int i = 1; i <= 10; i++) {
		// Calculate the new value of x using the given formula
		x = r*x - D;

		// Print the value of x to the console
		printf("%d\n", x);
	}

	return 0;
}

// The end of the code

