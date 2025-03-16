#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// Declare variables n and sum
	int n, sum;

	scanf("%d",&n);
	// Read an integer value from the user and store it in the variable n

	sum=(n*(n+1))/2;
	// Calculate the sum of the first n natural numbers
	// The formula for the sum of the first n natural numbers is n*(n+1)/2

	printf("%d\n",sum);
	// Print the calculated sum to the standard output

	return 0;
	// Indicate successful termination of the program
}

