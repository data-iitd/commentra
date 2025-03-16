#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // Declare a string variable to hold the input
    char source[11];
    // Read input from the user
    scanf("%s", source);

    // Check if the input length is valid (between 1 and 10 characters)
    if(strlen(source) > 10 || strlen(source) < 1)
    {
        // Return -1 if the input length is invalid
        return -1;
    }

    // Calculate the maximum number of combinations of '+' placements
    int max_i = (int)pow(2, strlen(source) - 1);

    // Initialize a variable to hold the cumulative sum of the evaluated expressions
    double sum = 0;

    // Iterate through all possible combinations of '+' placements
    for (int i = 0; i < max_i; ++i)
    {
        // Create a bitset to represent the current combination of '+' placements
        char plus[100];
        sprintf(plus, "%d", i);

        // Initialize a variable to hold the current number being evaluated
        double number = 0;

        // Create a working copy of the source string to manipulate
        char working[11];
        strcpy(working, source);
        // While there are still '+' placements to evaluate
        while(strchr(plus, '1'))
        {
            int i = 0;
            // Find the next position of a '1' in the bitset
            while(plus[i] != '1') ++i;
            // Convert the substring up to the current position to a double and add to sum
            sum += atof(working);
            // Shift the bitset to the right to evaluate the next segment
            memmove(plus, plus + i + 1, strlen(plus) - i);
            // Update the working string to remove the processed segment
            memmove(working, working + i + 1, strlen(working) - i);
        }
        // Add the remaining part of the working string to the sum
        sum += atof(working);
    }

    // Set the precision for output and print the final sum
    printf("%.0f\n", sum);

    return 0;
}

