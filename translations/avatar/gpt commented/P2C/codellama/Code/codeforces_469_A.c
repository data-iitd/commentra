#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Read the maximum level from user input
    int max_level;
    scanf("%d", &max_level);

    // Read the levels completed by player X and convert them to a list of integers
    int x_count;
    scanf("%d", &x_count);
    int x[x_count];
    for (int i = 0; i < x_count; i++)
    {
        scanf("%d", &x[i]);
    }

    // Read the levels completed by player Y and convert them to a list of integers
    int y_count;
    scanf("%d", &y_count);
    int y[y_count];
    for (int i = 0; i < y_count; i++)
    {
        scanf("%d", &y[i]);
    }

    // Remove the first element from both lists, which represents the count of levels
    x_count--;
    y_count--;

    // Convert the lists of levels into sets to eliminate duplicates
    int x_set[x_count];
    int y_set[y_count];
    for (int i = 0; i < x_count; i++)
    {
        x_set[i] = x[i];
    }
    for (int i = 0; i < y_count; i++)
    {
        y_set[i] = y[i];
    }

    // Check if player X has completed level 0, if so, remove it from the set
    if (x_set[0] == 0)
    {
        for (int i = 0; i < x_count; i++)
        {
            x_set[i] = x_set[i + 1];
        }
        x_count--;
    }
    // If player X has not completed level 0, check if player Y has, and remove it if present
    else if (y_set[0] == 0)
    {
        for (int i = 0; i < y_count; i++)
        {
            y_set[i] = y_set[i + 1];
        }
        y_count--;
    }

    // Create a union of both sets to combine all unique levels completed by both players
    int z_set[x_count + y_count];
    int z_count = 0;
    for (int i = 0; i < x_count; i++)
    {
        int found = 0;
        for (int j = 0; j < y_count; j++)
        {
            if (x_set[i] == y_set[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            z_set[z_count] = x_set[i];
            z_count++;
        }
    }
    for (int i = 0; i < y_count; i++)
    {
        int found = 0;
        for (int j = 0; j < x_count; j++)
        {
            if (y_set[i] == x_set[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            z_set[z_count] = y_set[i];
            z_count++;
        }
    }

    // Check if the number of unique levels completed matches the maximum level
    if (z_count != max_level)
    {
        // If not, print a message indicating that not all levels were completed
        printf("Oh, my keyboard!\n");
    }
    else
    {
        // If all levels were completed, print a success message
        printf("I become the guy.\n");
    }

    return 0;
}

