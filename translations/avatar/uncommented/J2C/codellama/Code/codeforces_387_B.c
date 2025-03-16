
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n, m, i, j, ans;
    scanf("%d %d", &n, &m);
    int *req = (int *)malloc(n * sizeof(int));
    int *pre = (int *)malloc(m * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &pre[i]);
    }
    i = n - 1;
    j = m - 1;
    ans = 0;
    while (i >= 0 && j >= 0)
    {
        if (req[i] > pre[j])
        {
            ans++;
        }
        else
        {
            j--;
        }
        i--;
    }
    printf("%d", ans + i + 1);
    return 0;
}

