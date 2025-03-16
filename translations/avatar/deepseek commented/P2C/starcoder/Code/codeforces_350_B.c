
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, x, crt, cnt[1000001];
    scanf("%d", &n);
    int t[n + 1], a[n + 1];
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &t[i]);
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= n; i++)
    {
        cnt[a[i]]++;
    }
    for (i = 1; i <= n; i++)
    {
        if (t[i] == 1)
        {
            crt = i;
            x = a[i];
            while (cnt[x] == 1)
            {
                crt = crt + 1;
                x = a[x];
            }
            if (crt > n)
            {
                printf("%d\n", crt);
                printf("%d\n", a[i]);
                return 0;
            }
        }
    }
    return 0;
}

