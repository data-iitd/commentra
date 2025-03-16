
#include <stdio.h>

int main()
{
    int t, n, s, t1, i;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        s = (1 + n) * n / 2;
        t1 = 1;
        for (i = 1; i <= n; i *= 2)
        {
            s -= 2 * t1;
            t1 *= 2;
        }
        printf("%d\n", s);
    }
    return 0;
}

