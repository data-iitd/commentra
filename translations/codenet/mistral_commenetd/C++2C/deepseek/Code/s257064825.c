#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str[1000];
    int sum = 0;

    // Read input string from standard input
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    // Iterate through each character in the string and add its ASCII value (after converting to digit) to sum
    for(int i = 0; i < strlen(str); i++)
    {
        sum += (str[i] - 48); // Subtract 48 to convert ASCII value of digit character to its integer value
    }

    // Check if sum is divisible by 9
    if(sum % 9 == 0)
    {
        printf("Yes\n"); // Output "Yes" if sum is divisible by 9
    }
    else
    {
        printf("No\n"); // Output "No" otherwise
    }

    return 0;
}
