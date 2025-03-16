#include <stdio.h>
#include <math.h>

// Define a type alias for long long integers
typedef long long ll;

// Main function that starts the execution of the program
int main(){
	// Read two integers 'n' and 'd' from the standard input
	int n, d;
	scanf("%d %d", &n, &d);

	// Calculate the value of 'a' as 'd' multiplied by 2 and adding 1
	double a = d*2+1;

	// Use the ceil function to find the smallest integer greater than or equal to the result of dividing 'n' by 'a'
	// Print the result to the standard output
	printf("%d\n", (int)ceil(n/a));

	// Return 0 to indicate successful execution of the program
	return 0;
}

