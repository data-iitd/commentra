#include <stdio.h>

int main() {
	// Declare three integer variables x, a, and b to store input values.
	int x, a, b;
	
	// Read three integers from the standard input and assign them to x, a, and b.
	scanf("%d %d %d", &x, &a, &b);
	
	// Use a switch statement to evaluate the condition b-a and execute the corresponding block of code.
	switch (b-a) {
		// If b-a is less than or equal to 0, print "delicious".
		case b-a <= 0:
			printf("delicious\n");
			break;
		// If b-a is greater than 0 but less than or equal to x, print "safe".
		case b-a <= x:
			printf("safe\n");
			break;
		// If b-a is greater than x, print "dangerous".
		default:
			printf("dangerous\n");
			break;
	}
	
	// End of code.
	return 0;
}