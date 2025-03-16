#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, count = 0;
    char *a, *b;

    // Ask user for the number of arrays (n) they want to input
    scanf("%d", &n);

    // Create an empty list called 'q' to store these arrays
    char **q = (char **)malloc(n * sizeof(char *));

    // Use a for loop to iterate through the range of 'n' and for each iteration,
    // ask the user for an array (a) and append it to our list 'q'
    for (i = 0; i < n; i++)
    {
        // Ask user for an array (a)
        scanf("%s", a);
        // Append array 'a' to our list 'q'
        q[i] = a;
    }

    // Use another for loop to iterate through each array in our list 'q'
    for (j = 0; j < n; j++)
    {
        // For each array 'j', use another for loop to iterate through every other array in our list 'q'
        for (k = 0; k < n; k++)
        {
            // Exclude the current array 'j' from comparison using 'continue' statement if they are the same
            if (k == j)
                continue;
            // Check if the last element of the second array 'k' matches the first element of the first array 'j'
            if (strcmp(q[j][0], q[k][strlen(q[k]) - 1]) == 0)
            {
                // If it does, increment our 'count' variable
                count++;
            }
        }
    }

    // Finally, print out the value of our 'count' variable
    printf("%d", count);

    // End of code
    return 0;
}
