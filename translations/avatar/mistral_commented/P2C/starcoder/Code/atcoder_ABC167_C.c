#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    // Take input dimensions and threshold from user
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    // Initialize 2D array 'c' with dimensions (n, m)
    int c[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }

    // Initialize empty lists 'l' for storing combinations and'rem' for storing indices
    int l[m + 1][m];
    int rem[m];

    // Initialize variable 'ans' for storing minimum number of tests
    int ans = 0;

    // Loop through all possible combinations of 'pre' indices
    for (int i = 0; i <= m; i++)
    {
        // Generate all combinations of 'pre' indices of size 'i'
        for (int j = 0; j < pow(2, i); j++)
        {
            // Initialize variable 'ca' to 0 for sum of tests in current combination
            int ca = 0;

            // Loop through each index 'k' in current combination
            for (int k = 0; k < i; k++)
            {
                // Add the test result at index 'k' and test case 'j' to 'ca'
                ca += c[k][j];
            }

            // If the sum of tests in current combination is less than threshold 'x',
            // add the index of the current combination to'rem' list
            if (ca < x)
            {
                rem[i] = j;
            }
            // If the sum of tests in current combination is greater than or equal to threshold 'x',
            // continue to next combination
            else
            {
                continue;
            }
        }
    }

    // If'rem' list is not empty, remove the combinations with indices in'rem' from 'l' list
    if (rem[0]!= 0)
    {
        for (int i = 0; i < m; i++)
        {
            if (rem[i]!= 0)
            {
                for (int j = i; j < m; j++)
                {
                    l[i][j] = l[i + 1][j];
                }
            }
        }
    }

    // If 'l' list is empty, print -1 and break the loop
    if (l[0][0] == 0)
    {
        printf("-1");
        return 0;
    }

    // If the loop completes without finding a valid combination,
    // calculate the minimum number of tests in all valid combinations
    else
    {
        // Initialize variable 'ca' to 0 for sum of tests in current combination
        int ca = 0;

        // Loop through each valid combination and calculate the sum of tests
        for (int i = 0; i < m; i++)
        {
            ca = 0;
            for (int j = 0; j < m; j++)
            {
                ca += c[j][i];
            }

            // Update 'ans' with minimum number of tests among all valid combinations
            if (ans == 0)
            {
                ans = ca;
            }
            else
            {
                ans = min(ans, ca);
            }
        }

        // Print the minimum number of tests required
        printf("%d", ans);
    }

    return 0;
}

