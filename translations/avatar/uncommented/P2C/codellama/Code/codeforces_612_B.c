#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, l, m, res;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int b[n];
    for (i = 0; i < n; i++)
    {
        b[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        b[a[i] - 1] = i;
    }
    res = 0;
    for (i = 1; i < n; i++)
    {
        res += abs(b[i] - b[i - 1]);
    }
    printf("%d", res);
    return 0;
}

