#include <stdio.h>
int main(void)
{
    int n, s, c, f, t, x;
    scanf("%d %d", &n, &s);
    c = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &f, &t);
        x = t - (s - f);
        if (x > c)
            c = x;
    }
    printf("%d", s + c);
    return 0;
}
