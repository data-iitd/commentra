#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Read the number of lines (n) from user input
    int n;
    scanf("%d", &n);

    // Initialize a list to store the cake representation and variables for happiness and chocolate count
    char cake[n][n];
    int happiness = 0;
    int chocCount = 0;
    int nfat = 1;

    // Process each line of cake input
    for (int i = 0; i < n; i++)
    {
        // Read a line of cake representation
        scanf("%s", cake[i]);

        // Count the number of chocolates ('C') in the current line
        for (int j = 0; j < n; j++)
        {
            if (cake[i][j] == 'C')
            {
                chocCount += 1;
            }
        }

        // If there are more than one chocolate, calculate the happiness contribution
        if (chocCount > 1)
        {
            // Calculate the factorial of (chocCount - 1) and (chocCount - 2)
            for (int i = chocCount; i > chocCount - 2; i--)
            {
                nfat *= i;
            }
            // Update happiness based on the calculated factorial
            happiness += nfat / 2;
        }

        // Reset variables for the next line
        nfat = 1;
        chocCount = 0;
    }

    // Initialize a counter for vertical chocolate counting
    int posCount = 0;

    // Count chocolates in each column of the cake
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            // Count the number of chocolates ('C') in the current column
            if (cake[i][j] == 'C')
            {
                chocCount += 1;
            }
        }

        // If there are more than one chocolate in the column, calculate the happiness contribution
        if (chocCount > 1)
        {
            // Calculate the factorial of (chocCount - 1) and (chocCount - 2)
            for (int i = chocCount; i > chocCount - 2; i--)
            {
                nfat *= i;
            }
            // Update happiness based on the calculated factorial
            happiness += nfat / 2;
        }

        // Reset variables for the next column
        nfat = 1;
        chocCount = 0;
    }

    // Print the total happiness as an integer
    printf("%d", happiness);

    return 0;
}

