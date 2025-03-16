#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define 'int' as 'long long int' for larger integer support
#define int long long int

int main()
{
    // Optimize input/output operations
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    // Declare a string to hold the input
    char str[1000000];
    // Read the input string from the user
    scanf("%s", str);
    
    // Initialize a variable to hold the sum of digits
    int sum = 0;
    
    // Iterate through each character in the string
    for(int i = 0; str[i] != '\0'; i++)
    {
        // Convert character to integer and add to sum
        sum += (str[i] - 48); // '48' is the ASCII value of '0'
    }
    
    // Check if the sum of digits is divisible by 9
    if(sum % 9 == 0)
    {
        // If divisible, print "Yes"
        printf("Yes\n");
    }
    else
    {
        // If not divisible, print "No"
        printf("No\n");
    }
    
    // End of code
    return 0;
}



