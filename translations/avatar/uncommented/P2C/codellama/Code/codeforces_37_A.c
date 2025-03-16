#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, l, m, high, tower, maximum;
    scanf("%d", &n);
    int *l = (int *)malloc(n * sizeof(int));
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
            tower--;
            high++;
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
    printf("%d %d\n", maximum, tower);
    return 0;
}
