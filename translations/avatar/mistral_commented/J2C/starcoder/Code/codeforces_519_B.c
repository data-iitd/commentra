#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, c, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        b += a;
    }
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &a);
        c += a;
    }
    x = a - b;
    y = b - c;
    printf("%d\n%d", x, y);
    return 0;
}

