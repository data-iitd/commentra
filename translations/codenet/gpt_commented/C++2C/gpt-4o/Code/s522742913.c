#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    // Declare a string variable to hold the input
    char source[11]; // Maximum length of 10 + 1 for null terminator
    // Read input from the user
    scanf("%10s", source);

    // Check if the input length is valid (between 1 and 10 characters)
    int length = strlen(source);
    if(length > 10 || length < 1)
    {
        // Return -1 if the input length is invalid
        return -1;
    }

    // Calculate the maximum number of combinations of '+' placements
    int max_i = (int)pow(2, length - 1);

    // Initialize a variable to hold the cumulative sum of the evaluated expressions
    double sum = 0;

    // Iterate through all possible combinations of '+' placements
    for (int i = 0; i < max_i; ++i)
    {
        // Initialize a variable to hold the current number being evaluated
        double number = 0;

        // Create a working copy of the source string to manipulate
        char working[11];
        strcpy(working, source);

        // Create a bitmask to represent the current combination of '+' placements
        int plus = i;

        // While there are still '+' placements to evaluate
        while (plus > 0)
        {
<<<<<<< HEAD
            // Find the position of the next '1' in the bitmask
            int j = 0;
            while ((plus & 1) == 0)
=======
            // Find the next position of a '1' in the bitmask
            int j = 0;
            while (!(plus & 1))
>>>>>>> 98c87cb78a (data updated)
            {
                plus >>= 1;
                j++;
            }

            // Convert the substring up to the current position to a double and add to sum
            char temp[11];
            strncpy(temp, working, j + 1);
            temp[j + 1] = '\0'; // Null-terminate the substring
            sum += atof(temp);

            // Shift the bitmask to the right to evaluate the next segment
            plus >>= 1;

            // Update the working string to remove the processed segment
            memmove(working, working + j + 1, strlen(working) - j);
        }

        // Add the remaining part of the working string to the sum
        sum += atof(working);
    }

    // Set the precision for output and print the final sum
    printf("%.0f\n", sum);

    return 0;
}

// <END-OF-CODE>
