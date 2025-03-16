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
        int a;
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
        printf("%d\n", -1);
    return 0;
}
