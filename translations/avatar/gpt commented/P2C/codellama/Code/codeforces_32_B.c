#include <stdio.h>
#include <string.h>

int main()
{
    // Declare a character array to store the input string
    char s[100];

    // Read input string from the user
    scanf("%s", s);

    // Declare a character array to store the result
    char result[100];

    // Initialize an empty string to store the result
    strcpy(result, "");

    // Initialize a counter variable to iterate through the input string
    int i = 0;

    // Loop through each character in the input string
    while (i < strlen(s))
    {
        // Check if the current character is a dot
        if (s[i] == '.')
        {
            // If it is a dot, append '0' to the result
            strcat(result, "0");
        }
        else
        {
            // If it is not a dot, increment the index to check the next character
            i++;

            // Check the next character
            if (s[i] == '.')
            {
                // If the next character is a dot, append '1' to the result
                strcat(result, "1");
            }
            else
            {
                // If the next character is not a dot, append '2' to the result
                strcat(result, "2");
            }
        }

        // Increment the index to move to the next character in the input string
        i++;
    }

    // Print the final result string
    printf("%s\n", result);

    return 0;
}

