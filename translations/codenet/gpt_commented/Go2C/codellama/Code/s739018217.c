#include <stdio.h>
#include <math.h>

int main() {
	// Declare variables n and m to hold the number of problems and the number of hard problems respectively
	int n, m;
	
	// Read input values for n and m from the standard input
	scanf("%d %d", &n, &m);
	
	// Calculate the total time required to solve the problems
	// The time for hard problems is 1900 each, and for easy problems is 100 each
	int x = m*1900 + (n-m)*100;
	
	// Calculate the total number of ways to solve the problems
	// This is done by multiplying the total time by 2 raised to the power of m (the number of hard problems)
	printf("%d\n", x * (int)pow(2.0, m));
	
	// End of code
	return 0;
}
