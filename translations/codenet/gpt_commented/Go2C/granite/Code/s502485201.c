
#include <stdio.h>

int main() {
	// Declare variables for radius (r), distance (d), and initial value (x)
	int r, d, x;
	
	// Read input values for r, d, and x from standard input
	scanf("%d %d %d", &r, &d, &x);

	// Loop 10 times to perform calculations based on the input values
	for (int i = 0; i < 10; i++) {
		// Update x using the formula: x = r * x - d
		x = r*x - d;
		
		// Print the updated value of x to the standard output
		printf("%d\n", x);
	}
	
	// End of code
	return 0;
}
