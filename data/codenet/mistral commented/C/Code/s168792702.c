#include <stdio.h>

// Include the standard input/output library

int main(void) {
	// Declare three integer variables: a, b, and c
	int a, b, c;

	// Use the scanf function to read three integers from the standard input and store them in variables a, b, and c
	scanf("%d %d %d", &a, &b, &c);

	// Check if the condition a < b and b < c is true. If it is, print "Yes" to the standard output using the puts function. Otherwise, print "No"
	if (a < b && b < c) {
		puts("Yes"); // If the condition is true, print "Yes"
	} else {
		puts("No"); // If the condition is false, print "No"
	}

	// Return 0 to indicate successful execution of the program
	return 0;
}
