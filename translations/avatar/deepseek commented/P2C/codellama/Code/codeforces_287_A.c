#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char t[4][4];  // Initialize a 4x4 array to store the input data.

    // Loop to take input and store it in the array t.
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%c", &t[i][j]);
        }
    }

    int black = 0;  // Initialize the count of black cells to 0.
    int white = 0;  // Initialize the count of white cells to 0.
    int correct = 0;  // Initialize the correct flag to 0.

    // Nested loop to iterate over the 3x3 grid formed by the first 3 rows and columns of t.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Count the number of black and white cells in the current 2x2 subgrid.
            if (t[i][j] == '#')
            {
                black++;
            }
            else
            {
                white++;
            }
            if (t[i][j + 1] == '#')
            {
                black++;
            }
            else
            {
                white++;
            }
            if (t[i + 1][j] == '#')
            {
                black++;
            }
            else
            {
                white++;
            }
            if (t[i + 1][j + 1] == '#')
            {
                black++;
            }
            else
            {
                white++;
            }

            // Check if the counts of black and white cells meet any of the specified conditions.
            if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4)
            {
                correct = 1;
                break;  // If conditions are met, set correct to 1 and break out of the loop.
            }

            black = 0;  // Reset the count of black cells.
            white = 0;  // Reset the count of white cells.
        }
    }

    // Print 'YES' if correct is 1, otherwise print 'NO'.
    if (correct == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}

