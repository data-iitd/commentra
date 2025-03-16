#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, count = 0;
    char **q;

    // Read an integer input which represents the number of lists to be processed
    scanf("%d", &n);

    // Initialize an empty list to store the input lists
    q = (char **)malloc(n * sizeof(char *));

    // Loop to read 'n' lines of input and store them in the list 'q'
    for (i = 0; i < n; i++)
    {
        // Read a line of input, split it into a list of strings, and append it to 'q'
        q[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", q[i]);
    }

    // Nested loop to compare each list in 'q' with every other list
    for (j = 0; j < n; j++)
    {
        for (k = 0; k < n; k++)
        {
            // Skip comparison if both lists are the same
            if (k == j)
                continue;
            // Check if the first element of list 'j' matches the last element of list 'k'
            else if (strcmp(q[j], q[k]) == 0)
            {
                // Increment the count if the condition is met
                count += 1;
            }
            else
            {
                // Continue to the next iteration if the condition is not met
                continue;
            }
        }
    }

    // Print the final count of matching conditions
    printf("%d", count);

    // Free the memory allocated to 'q'
    for (i = 0; i < n; i++)
    {
        free(q[i]);
    }
    free(q);

    return 0;
}

