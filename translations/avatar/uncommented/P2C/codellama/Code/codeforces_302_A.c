
#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, sa, a, b;
    char s[100000];

    scanf("%d %d", &n, &m);
    scanf("%s", s);
    sa = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '-')
            sa++;
    }
    sa = min(n - sa, sa);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        b -= a;
        if (b % 2 == 0 && b <= sa * 2)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}

