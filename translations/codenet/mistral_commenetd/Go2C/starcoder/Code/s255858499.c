
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Declare two integers a and b
	int a, b;
	// Read the first line from stdin and store it in variable a
	scanf("%d", &a);
	// Read the second line from stdin and store it in variable b
	scanf("%d", &b);
	// Check if the product of a and b is odd or even
	if (a*b%2!= 0) {
		// If the product is odd, print "Odd" to stdout
		printf("Odd");
	} else {
		// If the product is even, print "Even" to stdout
		printf("Even");
	}
	// Return from main
	return 0;
}

