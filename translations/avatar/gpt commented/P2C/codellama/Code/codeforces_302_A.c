#include <stdio.h>

int main()
{
    int n, m, sa, a, b, i;
    char ss[100000];

    scanf("%d %d", &n, &m);
    scanf("%d", &sa);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        b -= a;
        ss[i] = (b % 2 && b <= sa << 1) ? '1' : '0';
    }

    printf("%s", ss);

    return 0;
}

