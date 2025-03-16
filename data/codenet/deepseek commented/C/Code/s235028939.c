#include <stdio.h>  // Include the standard input-output library

int main()
{
	int n, m; // Declare two integer variables to store input values
	scanf("%d %d", &n, &m); // Read two integers from the standard input and store them in n and m
	printf("%d\n", (n - 1) * (m - 1)); // Print the result of the expression (n - 1) * (m - 1)
	fflush(stdout); // Ensure buffered output is written to the standard output stream immediately
	return 0; // Return 0 to indicate successful execution
}
