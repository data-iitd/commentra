#include <stdio.h>

int main() {
	// Include the stdio library for input and output operations
	
	// Define the main function, which is the entry point of the program
	
	// Declare three integer variables 'a', 'b', and 'c'
	int a, b, c;
	
	// Read three integers from the standard input and store them in 'a', 'b', and 'c'
	scanf("%d %d %d", &a, &b, &c);
	
	// Check if any of the following conditions are true:
	// - a + b equals c
	// - b + c equals a
	// - a + c equals b
	if (a + b == c || b + c == a || a + c == b) {
		// If any of these conditions are true, print "Yes".
		printf("Yes\n");
	} else {
		// Otherwise, print "No".
		printf("No\n");
	}
	
	// End the program
	return 0;
}
