#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, l, c, i;
    scanf("%d %d", &n, &k);
    l = 0;
    c = 1;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l);
        if (l == c)
            c++;
        else
            c = 1;
    }
    if (c + k > n)
        printf("%d\n", n - c);
    else
        printf("-1\n");
    return 0;
}
