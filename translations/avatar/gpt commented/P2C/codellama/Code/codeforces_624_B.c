
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, ans = 0, pre = 0;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        pre = max(0, min(pre - 1, a[i]));
        ans += max(0, min(pre - 1, a[i]));
    }
    printf("%d", ans);
    return 0;
}

