#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, a, b, j, i, x1, y1, c, count;
    bool ans;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    c = (x > y)? x : y;
    ans = true;
    if (c > b)
    {
        printf("0\n");
        ans = false;
    }
    while (c % ((x < y)? x : y)!= 0 && ans)
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
            printf("0\n");
            ans = false;
            break;
        }
    }
    if (ans)
    {
        count = 0;
        i = a;
        for (i = a; i <= b; i++)
        {
            if (i % c == 0)
                break;
        }
        if (i!= b + 1)
            printf("%d\n", (b - i) / c + 1);
        else
            printf("0\n");
    }
    return 0;
}
