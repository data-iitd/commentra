#include <stdio.h>

int main() {
	// Declare three integer variables named A, B, and C
	int A, B, C;

	// Use the "scanf" function to read three integers from the standard input
	// and assign them to the variables A, B, and C respectively
	scanf("%d %d %d", &A, &B, &C);

	// Check if the value of C is within the range of A and B
	if (C >= A && C <= B) {
		// If it is, print "Yes" to the standard output
		printf("Yes");
	} else {
		// Otherwise, print "No" to the standard output
		printf("No");
	}

	// End of code
}

