
#include <stdio.h>

int main() {
	// Declare three integer variables to store input values
	int a, b, c;
	
	// Read three integers from standard input and assign them to a, b, and c
	scanf("%d %d %d", &a, &b, &c);
	
	// Check if a is less than b and b is less than c
	if (a < b && b < c) {
		// If the condition is true, print "Yes"
		printf("Yes");
	} else {
		// Otherwise, print "No"
		printf("No");
	}
	
	// Return from the function
	return 0;
}

