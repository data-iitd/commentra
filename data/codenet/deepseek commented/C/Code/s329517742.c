#include<stdio.h> // Step 1: Include the standard input/output library.
int main() // Step 2: Define the main function.
{
	int a,b; // Step 3: Declare two integer variables a and b.
	scanf("%d %d",&a,&b); // Step 4: Read two integers from the user input.
	if(500*a>=b) printf("Yes\n"); // Step 5: Check if the product of 500 and a is greater than or equal to b.
	else printf("No\n"); // Step 6: Print "Yes" if the condition is true, otherwise print "No".
	return 0; // Step 7: End the main function and return 0.
}
