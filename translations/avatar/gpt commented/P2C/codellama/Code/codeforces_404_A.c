#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n, i, j, flag = 0;
    char **s;
    char *d1, *d2;
    char *rem;

    // Read the number of rows/columns for the square matrix
    scanf("%d", &n);

    // Initialize an empty list to store the input strings
    s = (char **)malloc(n * sizeof(char *));

    // Read n strings from input and append them to the list s
    for (i = 0; i < n; i++)
    {
        s[i] = (char *)malloc(n * sizeof(char));
        scanf("%s", s[i]);
    }

    // Initialize lists to store diagonal elements
    d1 = (char *)malloc(n * sizeof(char));
    d2 = (char *)malloc(n * sizeof(char));

    // Initialize a set to store non-diagonal elements
    rem = (char *)malloc(n * sizeof(char));

    // Iterate through the matrix to populate the diagonals and non-diagonal elements
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            // If it's a primary diagonal element
            if (i == j)
            {
                d1[i] = s[i][j];
            }
            // If it's a secondary diagonal element
            if (i == n - j - 1)
            {
                d2[i] = s[i][j];
            }
            // If it's a non-diagonal element
            if (i != j && i != n - j - 1)
            {
                rem[i] = s[i][j];
            }
        }
    }

    // Check conditions to determine the output
    // If the number of unique non-diagonal elements is not 1
    if (strlen(rem) != 1)
    {
        printf("NO\n");
    }
    // If the primary and secondary diagonals are not equal
    else if (strcmp(d1, d2) != 0)
    {
        printf("NO\n");
    }
    // If the primary diagonal does not consist of the same element
    else if (strlen(d1) != 1)
    {
        printf("NO\n");
    }
    // If the unique element in the primary diagonal is also in the non-diagonal set
    else if (strcmp(d1, rem) == 0)
    {
        printf("NO\n");
    }
    // If all conditions are satisfied, print 'YES'
    else
    {
        printf("YES\n");
    }

    // Free the memory allocated for the list s
    for (i = 0; i < n; i++)
    {
        free(s[i]);
    }
    free(s);

    // Free the memory allocated for the diagonals and non-diagonal elements
    free(d1);
    free(d2);
    free(rem);

    return 0;
}

