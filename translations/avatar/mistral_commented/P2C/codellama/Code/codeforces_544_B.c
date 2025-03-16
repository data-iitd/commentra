#######
# Code
#######

# Include header files
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int n, k, x = 0;

    // Read input: two integers n and k
    scanf("%d %d", &n, &k);

    // Check if k is valid based on the condition
    if (k <= (n * n) / 2 || k <= (n * n) - ((n * n) / 2))
    {
        // If k is valid, print 'YES'
        printf("YES\n");

        // Iterate through rows and columns of the grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Check if current position (i, j) is valid based on the condition
                if (i % 2 == j % 2 && x < k)
                {
                    // If valid, print 'L' and increment x
                    printf("L");
                    x++;
                }
                // If not valid, print 'S'
                else
                {
                    printf("S");
                }
            }
            // Move to the next line after completing a row
            printf("\n");
        }
    }
    // If k is not valid, print 'NO'
    else
    {
        printf("NO\n");
    }

    // End of code
    printf("