#include <stdio.h>
int main()
{
    int t, n, s, t1;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        s = (1 + n) * n / 2;
        t1 = 1;
        while (t1 <= n)
        {
            s -= 2 * t1;
            t1 *= 2;
        }
        printf("%d\n", s);
    }
    return 0;
}