
#include <stdio.h>

int main()
{
    // Define a constant string "abcd"
    char LUCKY[] = "abcd";

    // Ask the user to input an integer n
    int n;
    scanf("%d", &n);

    // Initialize an empty string s
    char s[1000];
    s[0] = '\0';

    // Use a for loop to iterate through the range of integers from 0 to n-1
    for (int i = 0; i < n; i++)
    {
        // Add the character at index i % 4 of the string LUCKY to the string s
        s[i] = LUCKY[i % 4];
    }

    // Print the final string s
    printf("%s\n", s);

    return 0;
}

