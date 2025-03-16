#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    // Initialize an empty string variable named 'source'
    char source[11]; // Maximum length of 10 + 1 for null terminator

    // Read a string input from the standard input stream (stdin) and store it in the 'source' variable
    scanf("%10s", source); // Limit input to 10 characters

    // Check if the length of the input string is valid (greater than 10 characters or less than 1 character)
    if (strlen(source) > 10 || strlen(source) < 1)
    {
        // If the condition is true, return an error code (-1)
        return -1;
    }

    // Calculate the maximum value of 'i' based on the length of the input string using bitwise operations
    int max_i = (int)pow(2, strlen(source) - 1);

    // Initialize a variable named 'sum' with a value of 0
    double sum = 0;

    // Iterate through the range of 'i' from 0 to 'max_i' using a for loop
    for (int i = 0; i < max_i; ++i)
    {
        // Initialize a variable named 'number' with a value of 0
        double number = 0;

        // Initialize a string variable named 'working' with the value of the input string 'source'
        char working[11];
        strcpy(working, source);

        // Create a variable to keep track of the current index in the 'working' string
        int working_length = strlen(working);

        // Iterate through the bits of 'i'
        for (int j = 0; j < working_length; ++j)
        {
            // Check if the j-th bit of i is set
            if (i & (1 << j))
            {
                // Add the substring of the 'working' string starting from the beginning to the j-th index to the 'sum' variable
                char temp[working_length + 1];
                strncpy(temp, working, j + 1);
                temp[j + 1] = '\0'; // Null-terminate the string
                sum += atof(temp);

                // Update the 'working' string by removing the substring that has been added to the 'sum' variable
                memmove(working, working + j + 1, working_length - (j + 1) + 1); // +1 for null terminator
                working_length = strlen(working);
                j = -1; // Reset j to start from the beginning of the new 'working' string
            }
        }

        // Add the remaining substring of the 'working' string to the 'sum' variable
        sum += atof(working);
    }

    // Set the precision of the output stream (stdout) to 0 decimal places
    printf("%.0f\n", sum);

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
