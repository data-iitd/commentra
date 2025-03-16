
#include<stdio.h>

int main()
{
	// Declare four integer variables to store user input
	int a, b, c, d; 
	
	// Read four integers from the standard input
	scanf("%d %d %d %d", &a, &b, &c, &d); 
	
	// Check if the product of a and b is odd and if the sum of c and d is also odd
	if (a*b%2==1 && (c+d)%2==1)
	{
		// If both conditions are true, print "No"
		printf("No\n");
	}
	else
	{
		// Otherwise, print "Yes"
		printf("Yes\n");
	}
}
