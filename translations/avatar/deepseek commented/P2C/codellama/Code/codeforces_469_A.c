#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int max_level, x[100], y[100], i, j, k, count = 0;
    bool flag = false;

    scanf("%d", &max_level);
    scanf("%d", &x[0]);
    scanf("%d", &y[0]);

    for (i = 1; i < x[0]; i++)
    {
        scanf("%d", &x[i]);
    }

    for (i = 1; i < y[0]; i++)
    {
        scanf("%d", &y[i]);
    }

    for (i = 0; i < x[0]; i++)
    {
        if (x[i] == 0)
        {
            flag = true;
            break;
        }
    }

    if (flag == true)
    {
        for (i = 0; i < x[0]; i++)
        {
            if (x[i] != 0)
            {
                x[count] = x[i];
                count++;
            }
        }
    }

    flag = false;

    for (i = 0; i < y[0]; i++)
    {
        if (y[i] == 0)
        {
            flag = true;
            break;
        }
    }

    if (flag == true)
    {
        for (i = 0; i < y[0]; i++)
        {
            if (y[i] != 0)
            {
                y[count] = y[i];
                count++;
            }
        }
    }

    for (i = 0; i < x[0]; i++)
    {
        for (j = 0; j < y[0]; j++)
        {
            if (x[i] == y[j])
            {
                count++;
            }
        }
    }

    if (count == max_level)
    {
        printf("I become the guy.");
    }
    else
    {
        printf("Oh, my keyboard!");
    }

    return 0;
}

