

#include <stdio.h> // Include the "stdio.h" header file for formatted I/O

int main() {
	// Declare a variable named "a" of type int
	int a;

	// Read a value of type int from the standard input and store it in the variable "a"
	scanf("%d", &a);

	// Calculate the result of the expression "a + a*a + a*a*a"
	int result = a + a*a + a*a*a;

	// Print the result to the standard output
	printf("%d\n", result);

	// End of code
	return 0;
}

