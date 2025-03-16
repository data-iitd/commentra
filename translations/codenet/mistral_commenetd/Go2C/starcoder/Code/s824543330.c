// Import the "stdio.h" library for formatted I/O
#include <stdio.h>

int main() {
	// Declare and initialize two integer variables, a and b, using scanf
	int a, b;
	scanf("%d %d", &a, &b);

	// Check if the product of a and b is even using the modulo operator (%).
	// If the result is zero, it means that a and b are both even or one of them is even and the other is a multiple of 2.
	if (a*b)%2 == 0 {
		// If the condition is true, print the message "Even"
		printf("Even\n");
	} else {
		// If the condition is false, print the message "Odd"
		printf("Odd\n");
	}
}

// End of code

