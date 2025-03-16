
#include<stdio.h>
#include<stdlib.h>

// Declare an integer variable 'n' and read its value from the standard input
int main()
{
	int n;
	scanf("%d", &n);

	// Output the result, which is calculated as (n - 2) * 180
	printf("%d\n", (n - 2) * 180);

	// Indicate successful termination of the program by returning 0
	return 0;
}

