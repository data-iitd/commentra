
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, a, b;
    int count = 0;
    int i, j;

    scanf("%d %d %d %d", &x, &y, &a, &b);

    for (i = a; i <= x; i++)
    {
        for (j = b; j <= y; j++)
        {
            if (i <= j)
                continue;
            count++;
        }
    }

    printf("%d\n", count);

    for (i = a; i <= x; i++)
    {
        for (j = b; j <= y; j++)
        {
            if (i <= j)
                continue;
            printf("%d %d\n", i, j);
        }
    }

    return 0;
}

