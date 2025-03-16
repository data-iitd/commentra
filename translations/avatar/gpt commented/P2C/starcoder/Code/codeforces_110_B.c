#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a constant string containing the characters 'a', 'b', 'c', and 'd'
    char LUCKY[] = "abcd";

    // Read an integer input from the user, which determines the length of the output string
    int n;
    scanf("%d", &n);

    // Initialize an empty string to store the result
    char s[n];

    // Loop through a range of 'n' to build the output string
    for (int i = 0; i < n; i++)
    {
        // Append the character from LUCKY based on the current index modulo 4
        // This ensures that the characters 'a', 'b', 'c', 'd' are repeated in the output
        s[i] = LUCKY[i % 4];
    }

    // Print the final constructed string
    printf("%s", s);

    return 0;
}
