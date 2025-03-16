
#include <stdio.h>

int main() {
	// Declare three integer variables to hold the input values
	int a, b, c;
	
	// Read three integers from the standard input and assign them to a, b, and c
	scanf("%d %d %d", &a, &b, &c);
	
	// Check if c is between a and b (inclusive)
	if (c >= a && c <= b) {
		// If true, print "Yes"
		printf("Yes\n");
	} else {
		// If false, print "No"
		printf("No\n");
	}
}

