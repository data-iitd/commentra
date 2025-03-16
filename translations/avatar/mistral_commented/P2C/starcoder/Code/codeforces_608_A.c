#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        int f, t;
        scanf("%d %d", &f, &t);
        int x = t - (s - f);
        if (x > c)
        {
            c = x;
        }
    }
    printf("%d", s + c);
    return 0;
}

