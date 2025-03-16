#include <stdio.h> // Include the stdio library for input/output operations
#include <stdlib.h> // Include the stdlib library for standard library functions

int main() // Begin the main function
{
	int a, b; // Declare two integer variables a and b
	scanf("%d %d", &a, &b); // Read the values of a and b from the standard input using scanf

	// Check if both a and b are less than or equal to 8
	if (a <= 8 && b <= 8) {
		printf("Yay!\n"); // If the condition is true, print "Yay!" to the standard output using printf
	}
	else {
		printf(":(\n"); // If the condition is false, print ":(" to the standard output using printf
	}

	// End the main function and return 0 to the operating system
	return 0;
}
