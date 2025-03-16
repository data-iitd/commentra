#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    // Include necessary libraries for input/output operations, mathematical calculations, and data structures.
	int n, d;
	scanf("%d %d", &n, &d);

    // Read the values of n and d from the standard input.
	double a = d * 2 + 1;
    // Calculate the value of 'a' which is used in the subsequent calculations.
	printf("%d\n", (int)ceil(n / a));
    // Output the ceiling of the division of n by 'a' to the standard output.

	return 0;
}

