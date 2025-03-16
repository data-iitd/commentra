#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int max_level, i, j, count;
    int *x, *y;
    char *s;

    scanf("%d", &max_level);
    x = (int *) malloc(sizeof(int) * (max_level + 1));
    y = (int *) malloc(sizeof(int) * (max_level + 1));
    s = (char *) malloc(sizeof(char) * (max_level + 1));

    scanf("%s", s);
    count = 0;
    for (i = 0; i < max_level; i++)
    {
        if (s[i] == '1')
        {
            x[count] = i;
            count++;
        }
    }
    x[count] = -1;
    count = 0;
    scanf("%s", s);
    for (i = 0; i < max_level; i++)
    {
        if (s[i] == '1')
        {
            y[count] = i;
            count++;
        }
    }
    y[count] = -1;

    for (i = 0; i < max_level; i++)
    {
        for (j = 0; j < max_level; j++)
        {
            if (x[i] == y[j])
            {
                x[i] = -1;
                y[j] = -1;
                break;
            }
        }
    }

    count = 0;
    for (i = 0; i < max_level; i++)
    {
        if (x[i]!= -1)
        {
            count++;
        }
    }

    if (count == max_level)
    {
        printf("I become the guy.\n");
    }
    else
    {
        printf("Oh, my keyboard!\n");
    }

    return 0;
}
