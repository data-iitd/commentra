
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, a, b, c, x, y;
    scanf("%d", &n);
    a = 0;
    b = 0;
    c = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
    }
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &b);
    }
    for (i = 0; i < n - 2; i++)
    {
        scanf("%d", &c);
    }
    x = a - b;
    y = b - c;
    printf("%d\n", x);
    printf("%d\n", y);
    return 0;
}

