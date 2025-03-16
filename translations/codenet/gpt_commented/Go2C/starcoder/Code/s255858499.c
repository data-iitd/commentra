

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// Read the first integer from input and convert it to an integer
	int a;
	scanf("%d", &a);
	// Read the second integer from input and convert it to an integer
	int b;
	scanf("%d", &b);

	// Check if the product of a and b is odd
	if (a*b) % 2!= 0 {
		// If the product is odd, print "Odd"
		printf("Odd");
	} else {
		// If the product is even, print "Even"
		printf("Even");
	}
}

