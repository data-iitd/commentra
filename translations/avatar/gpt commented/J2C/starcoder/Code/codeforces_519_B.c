#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, c, x, y;
    scanf("%d", &n);
    a = 0;
    b = 0;
    c = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        a += temp;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int temp;
        scanf("%d", &temp);
        b += temp;
    }
    for (int i = 0; i < n - 2; i++)
    {
        int temp;
        scanf("%d", &temp);
        c += temp;
    }
    x = a - b;
    y = b - c;
    printf("%d\n", x);
    printf("%d\n", y);
    return 0;
}
