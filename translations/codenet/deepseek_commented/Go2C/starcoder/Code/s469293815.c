#include <stdio.h>

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	// Read three integers from standard input
	// A, B, and C will store these values

	if (A+B >= C) {
		// Check if the sum of A and B is greater than or equal to C
		printf("Yes\n");
	} else {
		// If the sum is less than C, print "No"
		printf("No\n");
	}
}

