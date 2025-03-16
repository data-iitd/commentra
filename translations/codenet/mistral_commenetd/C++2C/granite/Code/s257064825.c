
#include<stdio.h>
#include<string.h>
#include<math.h>

// Initialize I/O streams
int main()
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	// Read input string from standard input
	char str[100000];
	fgets(str, 100000, stdin);

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
}

