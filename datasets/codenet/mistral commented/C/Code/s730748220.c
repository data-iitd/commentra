
#include<stdio.h> // Standard Input/Output library
#include<stdlib.h> // Standard Library for memory allocation and other functions
#include<limits.h> // Library for working with maximum and minimum values
#include<math.h> // Library for mathematical functions

int main(){
	// Declare variables
	int i,j,k,n;

	printf("Enter the value of n: ");
	scanf("%d",&n); // Read an integer value from the user and store it in variable n

	// Calculate and print the result
	printf("The result is: %d\n", 24 + (24-n));

	return 0; // Indicate successful execution of the program
}