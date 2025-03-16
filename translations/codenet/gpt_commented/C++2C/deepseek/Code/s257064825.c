#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define 'long long int' as 'long long' for larger integer support
#define long long long

int main()
{
    // Declare a character array to hold the input
    char str[1000];
    // Read the input string from the user
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character if present
    str[strcspn(str, "\n")] = 0;
    
    // Initialize a variable to hold the sum of digits
    long sum = 0;
    
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
}
