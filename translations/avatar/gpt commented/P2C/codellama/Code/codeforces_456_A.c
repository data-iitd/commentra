#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, m[100][2], a[2], b[2];

    // Read the number of rows (n) from user input
    scanf("%d", &n);

    // Read n rows of integers into a 2D array (matrix) m
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    // Sort the matrix m in descending order based on the first element of each row
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (m[i][0] < m[j][0])
            {
                for (k = 0; k < 2; k++)
                {
                    a[k] = m[i][k];
                    m[i][k] = m[j][k];
                    m[j][k] = a[k];
                }
            }
        }
    }

    // Initialize a variable a with the first row of the sorted matrix
    for (i = 0; i < 2; i++)
    {
        a[i] = m[0][i];
    }

    // Iterate through the remaining rows of the sorted matrix
    for (i = 1; i < n; i++)
    {
        // Check if the second element of the current row is greater than the second element of the previous row
        if (m[i][1] > a[1])
        {
            // If true, print 'Happy Alex' and exit the loop
            printf("Happy Alex\n");
            break;
        }
        // Update a to the current row for the next iteration
        for (j = 0; j < 2; j++)
        {
            a[j] = m[i][j];
        }
    }

    // If the loop completes without finding a greater second element, print 'Poor Alex'
    if (i == n)
    {
        printf("Poor Alex\n");
    }

    return 0;
}

