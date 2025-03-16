#include <stdio.h> // Include the stdio library for input and output operations

int main()
{
	int a; // Declare an integer variable 'a'
	scanf("%d", &a); // Read a value from the user and store it in 'a'
	printf("%d\n", (a + (a * a) + (a * a * a))); // Calculate and print the sum of 'a', 'a^2', and 'a^3'

	return 0; // Return 0 to indicate successful execution
}

