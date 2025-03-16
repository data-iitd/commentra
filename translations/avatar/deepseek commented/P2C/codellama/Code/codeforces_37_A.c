
#include <stdio.h>

int main()
{
    int n, i, j, k, l, m, high, tower, maximum;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &l[i]);
    }

    high = 1;
    tower = n;
    maximum = 1;

    for (i = 1; i < n; i++)
    {
        if (l[i] == l[i - 1])
        {
            tower -= 1;
            high += 1;
        }
        else
        {
            if (high > maximum)
            {
                maximum = high;
            }
            high = 1;
        }
    }

    if (high > maximum)
    {
        maximum = high;
    }

    printf("%d %d", maximum, tower);

    return 0;
}

