#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, l, c;
    scanf("%d %d", &n, &k);
    l = 0;
    c = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a == l)
            c += 1;
        else
            c = 1;
        l = a;
    }
    if (c + k > n)
        printf("%d", n - c);
    else
        printf("-1");
    return 0;
}
