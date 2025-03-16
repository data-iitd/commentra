#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, x, i, j, k, ca, ans = 0;
    scanf("%d %d %d", &n, &m, &x);
    int c[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    int pre[n];
    for (i = 0; i < n; i++)
    {
        pre[i] = i;
    }
    int l[n][n];
    int rem[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            l[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                l[i][j] = 1;
            }
        }
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            for (k = 0; k < i; k++)
            {
                l[j][j + k + 1] = l[j][j + k] + l[j + k][j + k + 1];
            }
        }
    }
    for (i = 1; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            ca = 0;
            for (k = 0; k < n; k++)
            {
                ca += c[j][k] * l[j][k];
            }
            if (ca < x)
            {
                rem[0] = j;
                for (k = 0; k < n - 1; k++)
                {
                    l[j][k] = l[j][k + 1];
                }
                l[j][n - 1] = 0;
            }
        }
        if (l[0][0] == 0)
        {
            printf("-1");
            return 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        ca = 0;
        for (j = 0; j < n; j++)
        {
            ca += c[j][0] * l[j][i];
        }
        if (ans == 0)
        {
            ans = ca;
        }
        else
        {
            ans = ans < ca ? ans : ca;
        }
    }
    printf("%d", ans);
    return 0;
}

