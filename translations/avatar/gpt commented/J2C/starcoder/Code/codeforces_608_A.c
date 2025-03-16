#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, s, f, t, max = 0;
    scanf("%d %d", &n, &s);
    while (n--)
    {
        scanf("%d %d", &f, &t);
        if (max < f + t)
            max = f + t;
    }
    printf("%d\n", max > s? max : s);
    return 0;
}

