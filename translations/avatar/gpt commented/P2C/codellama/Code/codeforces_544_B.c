#include <stdio.h>

int main()
{
    // Read two integers n and k from input
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize a counter to keep track of the number of 'L' printed
    int x = 0;

    // Check if k is less than or equal to the maximum number of 'L' that can be printed
    if (k <= (n * n) / 2)
    {
        // If the condition is satisfied, print 'YES'
        printf("YES\n");

        // Iterate over each row of the n x n grid
        for (int i = 0; i < n; i++)
        {
            // Iterate over each column of the n x n grid
            for (int j = 0; j < n; j++)
            {
                // Check if the current position (i, j) is in the same parity group and if we can still print 'L'
                if (i % 2 == j % 2 && x < k)
                {
                    // Print 'L' and increment the counter
                    printf("L");
                    x++;
                }
                else
                {
                    // Print 'S' if the conditions for 'L' are not met
                    printf("S");
                }
            }
            // Move to the next line after finishing a row
            printf("\n");
        }
    }
    else
    {
        // If k is greater than the maximum possible 'L', print 'NO'
        printf("NO\n");
    }

    // End of code
    printf("