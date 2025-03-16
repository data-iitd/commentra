#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, x, y, z;
    scanf("%d", &n);
    int a[n], b[n], c[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }
    x = 0;
    y = 0;
    z = 0;
    for (i = 0; i < n; i++)
    {
        x += a[i];
    }
    for (i = 0; i < n; i++)
    {
        y += b[i];
    }
    for (i = 0; i < n; i++)
    {
        z += c[i];
    }
    printf("%d\n", abs(x - y));
    printf("%d\n", abs(y - z));
    return 0;
}
