#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Initialize I/O streams
int main()
{
	// Read input string from standard input
	char str[1000000];
	scanf("%s",str);

	// Initialize sum variable to 0
	int sum=0;

	// Iterate through each character in the string and add its ASCII value (after converting to digit) to sum
	for(int i=0;i<strlen(str);i++)
	{
		sum+=(str[i]-48); // Subtract 48 to convert ASCII value of digit character to its integer value
	}

	// Check if sum is divisible by 9
	if(sum%9==0)
	{
		printf("Yes\n"); // Output "Yes" if sum is divisible by 9
	}
	else
	{
		printf("No\n"); // Output "No" otherwise
	}

	return 0;
}
