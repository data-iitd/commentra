


#include <stdio.h>

int main() {
	// Declare two integer variables A and B to hold input values
	int A, B;
	
	// Read two integers from standard input
	scanf("%d %d", &A, &B);

	// Declare a variable to hold the result
	int ans;
	
	// Check if A is between 6 and 12 (inclusive)
	if (6 <= A && A <= 12) {
		// If A is in the range, set ans to half of B
		ans = B / 2;
	} else if (12 < A) {
		// If A is greater than 12, set ans to the value of B
		ans = B;
	}
	
	// Print the result
	printf("%d", ans);
}

