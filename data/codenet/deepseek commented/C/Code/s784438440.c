#include<stdio.h>
int main()
{
	int a,b;
	
	// Read two integers a and b from the user
	scanf("%d %d",&a,&b);
	
	// Compute a value based on these inputs
	printf("%d\n",((b-1)+(a-2))/(a-1));
	
	// Print the computed value
	return 0;
}