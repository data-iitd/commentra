
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    // Declare a string variable to hold the input
    char source[101];
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
        bool plus[100];
        for (int j = 0; j < 100; ++j)
        {
            plus[j] = (i & (1 << j))!= 0;
        }

        // Initialize a variable to hold the current number being evaluated
        double number = 0;

        // Create a working copy of the source string to manipulate
        char working[101];
        strcpy(working, source);
        // While there are still '+' placements to evaluate
        int j = 0;
        while(plus[j])
        {
            // Find the next position of a '1' in the bitset
            while(!plus[j]) ++j;
            // Convert the substring up to the current position to a double and add to sum
            sum += atof(strndup(working, j + 1));
            // Shift the bitset to the right to evaluate the next segment
            for (int k = j; k < 100; ++k)
            {
                plus[k] = plus[k + 1];
            }
            // Update the working string to remove the processed segment
            memmove(working, working + j + 1, strlen(working + j + 1) + 1);
            // Reset j to start from the beginning of the working string
            j = 0;
        }
        // Add the remaining part of the working string to the sum
        sum += atof(working);
    }

    // Set the precision for output and print the final sum
    printf("%.0f\n", sum);

    return 0;
}
