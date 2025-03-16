

#include <stdio.h>

int main() {
	// Declare variables to hold input values
	int x, a, b;
	
	// Read three integer values from standard input
	scanf("%d %d %d", &x, &a, &b);
	
	// Evaluate the difference between b and a to determine the output
	switch {
		// Case when the difference is less than or equal to 0
		case b-a <= 0:
			printf("delicious"); // Output "delicious" if b is less than or equal to a
			break;
		// Case when the difference is less than or equal to x
		case b-a <= x:
			printf("safe"); // Output "safe" if the difference is within the limit x
			break;
		// Default case when the difference is greater than x
		default:
			printf("dangerous"); // Output "dangerous" if the difference exceeds x
			break;
	}
}

