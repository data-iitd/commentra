
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x, y, z, k;
    int a[100], b[100], c[100];
    int ab[100], abc[100];
    int i, j, kk;
    scanf("%d %d %d %d", &x, &y, &z, &k);
    for (i = 0; i < x; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < y; i++)
    {
        scanf("%d", &b[i]);
    }
    for (i = 0; i < z; i++)
    {
        scanf("%d", &c[i]);
    }
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            ab[i * y + j] = a[i] + b[j];
        }
    }
    for (i = 0; i < x * y; i++)
    {
        for (j = 0; j < z; j++)
        {
            abc[i * z + j] = ab[i] + c[j];
        }
    }
    for (i = 0; i < k; i++)
    {
        printf("%d\n", abc[i]);
    }
    return 0;
}

