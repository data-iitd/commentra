
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, x, y, z, cnt[1000001], t[1000001], a[1000001], ans[1000001];

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &t[i]);
    }

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 1; i <= n; i++)
    {
        cnt[i] = 0;
    }

    for (i = 1; i <= n; i++)
    {
        cnt[a[i]]++;
    }

    for (i = 1; i <= n; i++)
    {
        if (t[i] == 1)
        {
            x = i;
            y = a[i];
            z = 0;

            while (cnt[y] == 1)
            {
                z++;
                y = a[y];
            }

            if (z > ans[0])
            {
                ans[0] = z;
                ans[1] = x;
            }
        }
    }

    for (i = ans[0]; i >= 1; i--)
    {
        printf("%d ", ans[i]);
    }

    printf("\n");

    return 0;
}

