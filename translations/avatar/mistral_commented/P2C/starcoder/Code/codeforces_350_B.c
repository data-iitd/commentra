#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, x, y, cnt[1000001], ans[1000001], crt[1000001];

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        cnt[x]++;
    }

    for (i = 1; i <= n; i++)
    {
        if (t[i] == 1)
        {
            crt[0] = i;
            x = a[i];
            j = 1;
            while (cnt[x] == 1)
            {
                crt[j] = x;
                j++;
                x = a[x];
            }
            if (j > ans[0])
            {
                ans[0] = j;
                for (y = 0; y < j; y++)
                {
                    ans[y] = crt[y];
                }
            }
        }
    }

    for (i = 0; i < ans[0]; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}

