#include<stdio.h>
// Include the standard input/output library

int main(void)
// Function main is the starting point of the program
{
	int x;
	// Declare an integer variable x

	scanf("%d",&x);
	// Read an integer value from the standard input and store it in variable x

	printf("%d\n",x*x*x);
	// Print the result of x cubed to the standard output

	return 0;
	// Indicate successful termination of the program
}
