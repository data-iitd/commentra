
#include <stdio.h>

// Declare variables
int n;
unsigned long long int m;

int main(void) {
	// Initialize variables
	scanf("%d",&n);
	// Assign the value of n to m for later use
	m = n;
	// Decrement n by 1
	n--;

	// Loop through n-1 times to calculate the factorial
	for(; n > 1; n--) {
		// Multiply m with current value of n
		m *= n;
	}

	// Print the result
	printf("%lld\n", m);
	// Return 0 to indicate successful execution
	return 0;
}