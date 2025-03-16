#include <stdio.h> // Include the standard input/output library

int main() // The entry point of the program
{
	// Declare two integer variables n and m
	int n, m;

	// Use the scanf function to read two integers from the standard input and store them in n and m variables
	scanf("%d %d", &n, &m);

	// Calculate the product of (n - 1) and (m - 1) and store the result in the variable result
	int result = (n - 1) * (m - 1);

	// Use the printf function to print the result to the standard output
	printf("%d\n", result);

	// Flush the output buffer to ensure that all the data is written to the standard output before the program terminates
	fflush(stdout);

	// Indicate that the program has run successfully and terminate it
	return 0;
}
