#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, l, m, flag = 0;
    char **s, **d1, **d2;
    char *rem;

    // Take the number of rows as input
    scanf("%d", &n);

    // Initialize an empty list 's' to store the rows
    s = (char **)malloc(n * sizeof(char *));

    // Read each row and append it to the list 's'
    for (i = 0; i < n; i++)
    {
        // Read a row as a string and convert it to a list
        scanf("%s", s[i]);
    }

    // Initialize flags and empty lists 'd1' and 'd2'
    d1 = (char **)malloc(n * sizeof(char *));
    d2 = (char **)malloc(n * sizeof(char *));

    // Iterate through each element in the list 's'
    for (i = 0; i < n; i++)
    {
        // Iterate through each element in the same row and in the reverse order
        for (j = 0; j < n; j++)
        {
            // If the current indices are same, append the element to 'd1'
            if (i == j)
            {
                d1[i] = s[i][j];
            }
            // If the current indices are reverse of each other, append the element to 'd2'
            if (i == n - j)
            {
                d2[i] = s[i][j];
            }
            // If the current indices are not same and not reverse, add the element to 'rem' set
            if (i != j && i != n - j)
            {
                rem[i] = s[i][j];
            }
        }
    }

    // Check if the size of 'rem' set is not equal to 1
    if (strlen(rem) != 1)
    {
        // If the condition is true, print 'NO' and exit
        printf("NO\n");
        return 0;
    }

    // Check if 'd1' and 'd2' lists are equal
    if (strcmp(d1, d2) != 0)
    {
        // If the condition is true, print 'NO' and exit
        printf("NO\n");
        return 0;
    }

    // Check if all elements in 'd1' are same
    if (strlen(d1) != 1)
    {
        // If the condition is true, print 'NO' and exit
        printf("NO\n");
        return 0;
    }

    // Check if all elements in 'd1' are present in 'rem' set
    if (strcmp(d1, rem) != 0)
    {
        // If the condition is true, print 'NO' and exit
        printf("NO\n");
        return 0;
    }

    // If all the above conditions are false, print 'YES'
    printf("YES\n");

    return 0;
}

