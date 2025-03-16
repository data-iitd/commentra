#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, x, cnt[100001], t[100001], a[100001], ans[100001];
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
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
        cnt[a[i]]++;
    }
    for (i = 1; i <= n; i++)
    {
        if (t[i] == 1)
        {
            x = a[i];
            while (cnt[x] == 1)
            {
                ans[i] = x;
                x = a[x];
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (ans[i] != 0)
        {
            printf("%d ", ans[i]);
        }
    }
    printf("\n");
    return 0;
}