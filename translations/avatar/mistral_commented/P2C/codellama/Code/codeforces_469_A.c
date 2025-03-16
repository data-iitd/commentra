#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    // User inputs the maximum level of the set
    int max_level;
    scanf("%d", &max_level);

    // User inputs two lists, x and y, separated by a newline
    int x[100], y[100];
    char input[100];
    fgets(input, 100, stdin);
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL)
    {
        x[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }
    fgets(input, 100, stdin);
    token = strtok(input, " ");
    i = 0;
    while (token != NULL)
    {
        y[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    // Remove the first element from both lists, as they are not part of the sets
    x[0] = x[1];
    y[0] = y[1];

    // Convert both lists to sets for faster set operations
    int x_set[100], y_set[100];
    int x_set_size = 0, y_set_size = 0;
    for (int i = 1; i < 100; i++)
    {
        if (x[i] != 0)
        {
            x_set[x_set_size] = x[i];
            x_set_size++;
        }
        if (y[i] != 0)
        {
            y_set[y_set_size] = y[i];
            y_set_size++;
        }
    }

    // Check if zero is present in the first set
    bool zero_in_x = false;
    for (int i = 0; i < x_set_size; i++)
    {
        if (x_set[i] == 0)
        {
            zero_in_x = true;
            break;
        }
    }
    // Else, check if zero is present in the second set
    if (!zero_in_x)
    {
        for (int i = 0; i < y_set_size; i++)
        {
            if (y_set[i] == 0)
            {
                zero_in_x = true;
                break;
            }
        }
    }
    // If it is, remove it
    if (zero_in_x)
    {
        for (int i = 0; i < x_set_size; i++)
        {
            if (x_set[i] == 0)
            {
                x_set[i] = x_set[x_set_size - 1];
                x_set_size--;
                break;
            }
        }
        for (int i = 0; i < y_set_size; i++)
        {
            if (y_set[i] == 0)
            {
                y_set[i] = y_set[y_set_size - 1];
                y_set_size--;
                break;
            }
        }
    }

    // Combine both sets into a new set z
    int z[100];
    int z_size = 0;
    for (int i = 0; i < x_set_size; i++)
    {
        z[z_size] = x_set[i];
        z_size++;
    }
    for (int i = 0; i < y_set_size; i++)
    {
        z[z_size] = y_set[i];
        z_size++;
    }

    // Check if the size of the combined set is equal to the maximum level
    if (z_size != max_level)
    {
        // If not, print an error message
        printf("Oh, my keyboard!\n");
    }
    else
    {
        // Else, print a success message
        printf("I become the guy.\n");
    }

    return 0;
}

