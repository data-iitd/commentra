
#include<stdio.h> // Include the standard input/output library for input and output operations.
int main(void) // Define the main function, the entry point of the program.
{
	int n,k,x,y,z; // Declare five integer variables to store values.
	scanf("%d",&n); // Read an integer value for n from the standard input.
	scanf("%d",&k); // Read an integer value for k from the standard input.
	x=n/k; // Calculate the integer division of n by k and store the result in x.
	y=n%k; // Calculate the remainder of the integer division of n by k and store the result in y.
	if(y!=0) { // Check if the remainder y is not equal to 0.
		z=x+1-x; // If y is not equal to 0, calculate z as x+1-x.
	}
	else { // If y is equal to 0.
		z=x-x; // Calculate z as x-x.
	}
	printf("%d\n",z); // Print the value of z to the standard output.
	
	return 0; // Return 0 to indicate successful execution.
}

