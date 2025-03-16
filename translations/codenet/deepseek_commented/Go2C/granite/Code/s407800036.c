

#include <stdio.h>

int main() {
	// Code for A - Between Two Integers
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	// Read three integers A, B, and C from standard input
	// Check if C is between A and B (inclusive)
	if (C >= A && C <= B) {
		// If C is between A and B, print "Yes"
		printf("Yes\n");
	} else {
		// If C is not between A and B, print "No"
		printf("No\n");
	}
}

