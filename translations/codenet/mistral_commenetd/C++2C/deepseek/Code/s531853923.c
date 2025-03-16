#include <stdio.h>  // Include the standard input-output library for input and output operations
#include <stdbool.h>  // Include the stdbool library for boolean type

int main()  // Declare the main function, which is the entry point of the program
{
	// Declare four integer variables to store input values
	int a, b, c, d;

	// Read input values from the user using scanf
	scanf("%d %d %d %d", &a, &b, &c, &d);

	// Check if the condition is true
	if (a*b%2==1 && (c+d)%2==1)
	{
		// If the condition is true, print "No" to the output stream
		printf("No\n");
	}
	// If the condition is false, print "Yes" to the output stream
	else
	{
		printf("Yes\n");
	}
}
