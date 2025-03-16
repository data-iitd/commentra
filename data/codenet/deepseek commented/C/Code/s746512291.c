#include<stdio.h>  // Include the standard input/output library

int main(void) {  // Define the main function
	int x;  // Declare an integer variable
	scanf("%d", &x);  // Read an integer from the user
	printf("%d\n", x * x * x);  // Calculate and print the cube of the input value
	return 0;  // Return from the main function
}
