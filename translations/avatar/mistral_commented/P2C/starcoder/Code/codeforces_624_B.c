#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int pre = INT_MAX;
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        ans += max(0, min(pre - 1, a[j]));
        pre = min(pre - 1, a[j]);
    }
    printf("%d", ans);
    return 0;
}
