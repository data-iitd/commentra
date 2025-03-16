
#include<stdio.h> // Include the standard input/output library

int main() // Declare the main function
{
	int a, b, h; // Declare three integer variables: a, b, and h

	printf("Enter the values of a, b, and h: "); // Print a message asking for user input
	scanf("%d%d%d",&a,&b,&h); // Read three integers from the user and store them in variables a, b, and h

	// Calculate the area of the rectangle using the formula: area = length * width
	printf("%d\n",(a+b)*h/2); // Print the result, which is the area of the rectangle

	return 0; // Indicate that the program has run successfully
}