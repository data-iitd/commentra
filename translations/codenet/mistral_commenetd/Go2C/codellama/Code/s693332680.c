// Importing necessary packages
#include <stdio.h>
#include <stdlib.h>

// Declaring variables
int main() {
	int x, a, b;

	// Reading input values from standard input
	scanf("%d %d %d", &x, &a, &b);

	// Logic block to check if b is less than or equal to a
	switch (b-a) {
		// Base case: If b is less than or equal to a
		case 0:
			printf("delicious\n");
			break;

		// Next case: If b is greater than a but less than or equal to x
		case 1:
			printf("safe\n");
			break;

		// Default case: If none of the above conditions are met
		default:
			printf("dangerous\n");
			break;
	}

	// End of code
	return 0;
}

// End of code


