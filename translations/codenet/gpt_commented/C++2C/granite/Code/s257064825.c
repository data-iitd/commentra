
#include<stdio.h>
#include<string.h>
#include<math.h>

// Define 'int' as 'long long int' for larger integer support
#define int long long int

int main()
{
    // Optimize input/output operations
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    
    // Declare a string to hold the input
    char str[1000001];
    // Read the input string from the user
    fgets(str, 1000001, stdin);
    
    // Initialize a variable to hold the sum of digits
    int sum = 0;
    
    // Iterate through each character in the string
    for(int i = 0; i < strlen(str); i++)
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
    
    return 0;
}
