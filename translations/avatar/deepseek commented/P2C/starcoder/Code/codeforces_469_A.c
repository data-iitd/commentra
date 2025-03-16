#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max_level, i, j, x[1000], y[1000];
    scanf("%d", &max_level);
    for (i = 0; i < max_level; i++)
        scanf("%d", &x[i]);
    for (j = 0; j < max_level; j++)
        scanf("%d", &y[j]);
    for (i = 0; i < max_level; i++)
        x[i]--;
    for (j = 0; j < max_level; j++)
        y[j]--;
    for (i = 0; i < max_level; i++)
        if (x[i] == 0)
            x[i] = 1;
    for (j = 0; j < max_level; j++)
        if (y[j] == 0)
            y[j] = 1;
    int z[1000];
    int k = 0;
    for (i = 0; i < max_level; i++)
        for (j = 0; j < max_level; j++)
            if (x[i] == y[j])
                z[k++] = x[i];
    if (k == max_level)
        printf("I become the guy.\n");
    else
        printf("Oh, my keyboard!\n");
    return 0;
}
