
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long x, y, a, b, j, i, x1, y1, c;
    int ans = 1;
    scanf("%ld %ld %ld %ld", &x, &y, &a, &b);
    j = 2;
    i = 0;
    x1 = 0;
    y1 = 0;
    c = 0;
    c = max(x, y);
    if (c > b)
    {
        printf("0");
        ans = 0;
    }
    while (c % min(x, y) != 0 && ans)
    {
        if (x > y)
        {
            c = x * j;
            j++;
        }
        else
        {
            c = y * j;
            j++;
        }
        if (c > b)
        {
            printf("0");
            ans = 0;
            break;
        }
    }
    if (ans)
    {
        long count = 0;
        i = a;
        for (i = a; i <= b; i++)
        {
            if (i % c == 0)
                break;
        }
        if (i != b + 1)
            printf("%ld", (b - i) / c + 1);
        else
            printf("0");
    }
    return 0;
}

