#include <stdio.h>

// Step 1: Include necessary libraries and declare variables
// We include the stdio library for input and output operations.
// We declare two integer variables, N and A, to store user input.

int N, A;

int main() {
	// Step 2: Read input values
	// We read two integer values from the standard input and store them in variables N and A.
	scanf("%d %d", &N, &A);
	
	// Step 3: Perform the required operation
	// We check if the remainder of N divided by 500 is less than or equal to A.
	// If the condition is true, we print "Yes"; otherwise, we print "No".
	printf("%s\n", (N % 500 <= A) ? "Yes" : "No");
	
	// Step 4: Return from the main function
	// We return 0 to indicate successful execution of the program.
	return 0;
}
