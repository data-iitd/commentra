#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    // Step 1: Input Handling
    // The program starts by taking a string input from the user.
    char source[11]; // Maximum length of 10 + 1 for null terminator
    scanf("%10s", source); // Read up to 10 characters

    // It checks if the length of the input string is within the valid range (1 to 10 characters).
    // If not, it returns -1.
    int length = strlen(source);
    if(length > 10 || length < 1)
    {
        return -1;
    }

    // Step 2: Calculation Setup
    // The program calculates the maximum number of combinations that can be formed
    // by placing '+' signs between the digits of the input string.
    // This is done using the formula 2^(n-1), where n is the length of the input string.
    int max_i = (int)pow(2, length - 1);

    // Step 3: Iterating Over Combinations
    // The program iterates over all possible combinations of placing '+' signs between the digits.
    // For each combination, it calculates the sum of the numbers formed by the substrings separated by '+' signs.
    double sum = 0;

    for (int i = 0; i < max_i; ++i)
    {
        // Create a bit representation of the current combination
<<<<<<< HEAD
        unsigned int plus = i;
        double number = 0;

        char working[11];
        strcpy(working, source);
        char *token = strtok(working, "");

        // Process the string based on the current combination of '+' signs
        while (plus)
        {
            int j = 0;
            while (!(plus & 1)) // Find the next '1' bit
            {
                j++;
                plus >>= 1;
            }
            // Convert the substring to a number and add to sum
            char temp[11];
            strncpy(temp, source, j + 1);
            temp[j + 1] = '\0'; // Null-terminate the substring
            sum += atof(temp);
            // Shift the plus to the right for the next iteration
            plus >>= 1;
            source += j + 1; // Move the source pointer forward
        }
        // Add the last remaining part of the string
        sum += atof(source);
=======
        char plus[100] = {0}; // To store the bit representation
        for (int j = 0; j < length - 1; j++)
        {
            plus[j] = (i & (1 << j)) ? 1 : 0; // Set bit if 1
        }

        double number = 0;
        char working[11];
        strcpy(working, source); // Copy source to working

        int pos = 0; // Position in the working string
        while (1)
        {
            // Find the next '+' position
            int j = 0;
            while (j < length - 1 && !plus[j]) ++j;

            // If we found a '+' position
            if (j < length - 1)
            {
                // Convert the substring to a number and add to sum
                char temp[11] = {0}; // Temporary string to hold the number
                strncpy(temp, working, j + 1);
                sum += atof(temp);
                // Shift the working string
                memmove(working, working + j + 1, length - (j + 1) + 1);
                length -= (j + 1);
            }
            else
            {
                // If no more '+' positions, add the remaining number
                sum += atof(working);
                break;
            }
        }
>>>>>>> 98c87cb78a (data updated)
    }

    // Step 4: Output
    // Finally, the program outputs the sum of all possible combinations.
    printf("%.0f\n", sum);

    return 0;
}

// <END-OF-CODE>
