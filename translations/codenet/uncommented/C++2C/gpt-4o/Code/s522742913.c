#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char source[11]; // Maximum length of 10 + 1 for null terminator
    scanf("%10s", source); // Read up to 10 characters

    int length = strlen(source);
    if(length > 10 || length < 1)
    {
        return -1;
    }

    int max_i = (int)pow(2, length - 1);
    double sum = 0;

    for (int i = 0; i < max_i; ++i)
    {
<<<<<<< HEAD
        unsigned int plus = i; // Use unsigned int to represent bitset
        double number = 0;

        char working[11]; // Temporary string to hold working value
=======
        int plus = i;
        double number = 0;
        char working[11]; // Temporary string to hold the working copy
>>>>>>> 98c87cb78a (data updated)
        strcpy(working, source);

        while (plus)
        {
            int j = 0;
            while (!(plus & 1)) // Find the first bit that is set
            {
                plus >>= 1;
                j++;
            }
            sum += atof(strndup(working, j + 1)); // Convert substring to double
            plus >>= 1; // Shift right to process the next bit
<<<<<<< HEAD
            working[j + 1] = '\0'; // Null-terminate the working string
            strcpy(working, working + j + 1); // Update working string
        }
        sum += atof(working); // Add the remaining part
=======
            memmove(working, working + j + 1, strlen(working) - j); // Move the string left
        }
        sum += atof(working); // Add the last remaining part
>>>>>>> 98c87cb78a (data updated)
    }

    printf("%.0f\n", sum); // Print the sum with no decimal places

    return 0;
}

// <END-OF-CODE>
