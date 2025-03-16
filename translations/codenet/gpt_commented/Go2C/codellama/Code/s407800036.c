#include <stdio.h>

int main() {
	// Declare variables A, B, and C to hold integer values
	int A, B, C;
	
	// Read three integers from standard input
	scanf("%d %d %d", &A, &B, &C);

	// Check if C is within the range defined by A and B (inclusive)
	if (C >= A && C <= B) {
		// If C is within the range, print "Yes"
		printf("Yes\n");
	} else {
		// If C is outside the range, print "No"
		printf("No\n");
	}
	
	// End of code
	return 0;
}
