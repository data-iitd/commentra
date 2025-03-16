#include <stdio.h>
#include <string.h>

int main()
{
    // Declare a string variable to store the input
    char s[100]; // Assuming the input string will not exceed 99 characters

    // Read input string from the user
    scanf("%s", s);

    // Loop through each character from 'a' to 'z'
    for (char i = 'a'; i <= 'z'; i++)
    {
        // Initialize a counter to track occurrences of the current character
        int a = 0;

        // Loop through each character in the input string
        for (int j = 0; j < strlen(s); j++)
        {
            // Check if the current character matches the character being checked
            if (i == s[j])
            {
                // Increment the counter if a match is found
                a++;
            }
        }

        // If the character was not found in the input string
        if (a == 0)
        {
            // Output the first missing character and exit the loop
            printf("%c\n", i);
            break;
        } 

        // If we reach the end of the alphabet and all characters are present
        if (i == 'z')
        {
            // Output "None" if no characters are missing
            printf("None\n");
            break;
        }
    }
}

// <END-OF-CODE>
