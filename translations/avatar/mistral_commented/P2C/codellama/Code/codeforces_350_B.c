#include <stdio.h>

int main()
{
    int n, i, j, k, x, y, z, cnt[100001], t[100001], a[100001], ans[100001];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &t[i]);
    }

    for (i = 0; i < n; i++)
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

    for (i = ans[0]; i > 0; i--)
    {
        printf("%d ", ans[i]);
    }

    printf("\n");

    return 0;
}

