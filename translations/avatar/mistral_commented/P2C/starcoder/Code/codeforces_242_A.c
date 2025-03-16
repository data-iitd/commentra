#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Get user input as a string and convert it to a list of integers
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    // Initialize an empty list to store the games
    int games[x][y];
    // Iterate through a range of numbers from a to x+1
    for (int i = a; i <= x; i++)
    {
        // If i is less than or equal to b, skip to the next iteration
        if (i <= b)
        {
            continue;
        }
        // Iterate through a range of numbers from b to y+1
        for (int j = b; j <= y; j++)
        {
            // If i is greater than j, append the tuple (i, j) to the games list
            if (i > j)
            {
                games[i][j] = 1;
            }
        }
    }
    // Print the length of the games list
    printf("%d\n", x);
    // Iterate through the games list and print each tuple
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (games[i][j] == 1)
            {
                printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}
