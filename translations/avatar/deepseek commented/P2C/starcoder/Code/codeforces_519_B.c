
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int b[n];
    int c[n];
    int x = 0;
    int y = 0;
    int z = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        x += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        y += b[i];
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
        z += c[i];
    }
    printf("%d\n", abs(x - y));
    printf("%d\n", abs(y - z));
    return 0;
}

