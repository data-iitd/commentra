
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, a, b;
    int count = 0;

    // Read four integers from the console
    scanf("%d %d %d %d", &x, &y, &a, &b);

    // Find the number of pairs (i, j) that satisfy the condition i < j
    for (int i = a; i <= x; i++)
    {
        for (int j = b; j <= y; ++j)
        {
            // If i is less than j, continue to the next iteration of the inner loop
            if (i <= j) continue;

            // Increment the counter if the condition is satisfied
            count++;
        }
    }

    // Print the result
    printf("%d\n", count);

    // Print all pairs (i, j) that satisfy the condition i < j
    for (int i = a; i <= x; i++)
    {
        for (int j = b; j <= y; ++j)
        {
            // If i is less than j, print the pair
            if (i <= j)
            {
                printf("%d %d\n", i, j);
            }
        }
    }

    // Close the Scanner object to free system resources
    //in.close();

    return 0;
}

