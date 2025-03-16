
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, l, c, a;
    scanf("%d %d", &n, &k);
    l = 0;
    c = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a == l)
            c++;
        else
            c = 1;
        l = a;
    }
    if (c + k > n)
        printf("%d\n", n - c);
    else
        printf("-1\n");
    return 0;
}

