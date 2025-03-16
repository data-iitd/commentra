#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n, i, j, k, a[100000], max = 0, temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] % a[0] == 0)
        {
            max = a[i];
            break;
        }
    }
    if (max == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%d", max);
    }
    return 0;
}

