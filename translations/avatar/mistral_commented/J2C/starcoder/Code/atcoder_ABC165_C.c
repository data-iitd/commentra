
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a[100000], b[100000], c[100000], d[100000];
    int n, m, q, i, j, k, l, ans = -100;
    scanf("%d %d %d", &n, &m, &q);
    for(i = 0; i < q; i++)
    {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        a[i]--;
        b[i]--;
    }
    for(i = 0; i <= m; i++)
    {
        int list[100000] = {0};
        list[0] = i;
        dfs(list, 0, n, q, a, b, c, d, ans);
    }
    printf("%d\n", ans);
    return 0;
}

void dfs(int list[], int index, int n, int q, int a[], int b[], int c[], int d[], int &ans)
{
    if(index == n)
    {
        int score = 0;
        for(i = 0; i < q; i++)
        {
            if(list[b[i]] - list[a[i]] == c[i])
                score += d[i];
        }
        ans = max(ans, score);
        return;
    }
    if(index == 0)
    {
        for(i = 1; i <= m; i++)
        {
            list[index] = i;
            dfs(list, index + 1, n, q, a, b, c, d, ans);
        }
    }
    else
    {
        for(i = list[index - 1] + 1; i <= m; i++)
        {
            list[index] = i;
            dfs(list, index + 1, n, q, a, b, c, d, ans);
        }
    }
}

