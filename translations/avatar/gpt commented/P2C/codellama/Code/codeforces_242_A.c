#include <stdio.h>

int main()
{
    // Read input values for x, y, a, and b and convert them to integers
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);

    // Initialize an empty list to store valid game pairs
    int games[10000][2];
    int count = 0;

    // Iterate over the range from a to x (inclusive)
    for (int i = a; i <= x; i++)
    {
        // Skip the iteration if i is less than or equal to b
        if (i <= b)
        {
            continue;
        }
        else
        {
            // Iterate over the range from b to y (inclusive)
            for (int j = b; j <= y; j++)
            {
                // Check if the current i is greater than j
                if (i > j)
                {
                    // If the condition is met, append the pair (i, j) to the games list
                    games[count][0] = i;
                    games[count][1] = j;
                    count++;
                }
            }
        }
    }

    // Print the total number of valid game pairs found
    printf("%d\n", count);

    // Print each valid game pair
    for (int i = 0; i < count; i++)
    {
        printf("%d %d\n", games[i][0], games[i][1]);
    }

    return 0;
}

