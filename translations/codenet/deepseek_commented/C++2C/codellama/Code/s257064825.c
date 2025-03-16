#include<stdio.h>          // Include input/output stream library
#include<stdlib.h>         // Include standard library
#include<string.h>         // Include string library
#define int long long int // Define a custom integer type

int main()
{
	char str[1000000];                 // Declare a string variable to store input
	scanf("%s",str);                   // Read input string
	int sum=0;                         // Initialize sum variable to store the sum of digits
	for(int i=0;str[i]!='\0';i++)      // Iterate over each character in the string
	{
		sum+=(str[i]-48);              // Convert character to integer and add to sum
	}
	if(sum%9==0)                       // Check if sum is divisible by 9
	{
        printf("Yes\n");               // Print "Yes" if sum is divisible by 9
	}
	else                               // Otherwise
	   printf("No\n");                 // Print "No"
	return 0;                          // Return 0
}
