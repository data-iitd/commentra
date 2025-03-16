
#include <stdio.h>

int main() {
	// Initialize variables r, d, and x with given values
	int r, d, x;
	scanf("%d %d %d", &r, &d, &x);

	// Loop through 10 iterations
	for (int i = 0; i < 10; i++) {
		// Calculate new value of x using given formula
		x = r*x - d;

		// Print the current value of x
		printf("%d\n", x);
	}
}

