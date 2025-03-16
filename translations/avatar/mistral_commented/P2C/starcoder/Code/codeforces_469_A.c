#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max_level, i, j, x[100], y[100], z[100];

    scanf("%d", &max_level);

    for (i = 0; i < max_level; i++)
    {
        scanf("%d", &x[i]);
    }

    for (j = 0; j < max_level; j++)
    {
        scanf("%d", &y[j]);
    }

    for (i = 0; i < max_level; i++)
    {
        if (x[i] == 0)
        {
            x[i] = 1;
        }
    }

    for (j = 0; j < max_level; j++)
    {
        if (y[j] == 0)
        {
            y[j] = 1;
        }
    }

    for (i = 0; i < max_level; i++)
    {
        z[i] = x[i] + y[i];
    }

    if (z[0] == 0)
    {
        printf("Oh, my keyboard!\n");
    }
    else
    {
        printf("I become the guy.\n");
    }

    return 0;
}
