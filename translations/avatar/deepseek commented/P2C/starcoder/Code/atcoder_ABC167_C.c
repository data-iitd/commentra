#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    int c[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    int pre[n];
    for (int i = 0; i < n; i++)
    {
        pre[i] = i;
    }
    int l[n][m];
    int rem[n];
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            int ca = 0;
            for (int ii = 0; ii < i; ii++)
            {
                ca += c[j][ii];
            }
            if (ca < x)
            {
                rem[count] = j;
                count++;
            }
        }
        for (int j = 0; j < count; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (rem[j] == k)
                {
                    l[k][i - 1] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int ca = 0;
        for (int j = 0; j < m; j++)
        {
            ca += c[i][j];
        }
        if (ans == 0)
        {
            ans = ca;
        }
        else
        {
            ans = min(ans, ca);
        }
    }
    if (ans == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%d", ans);
    }
    return 0;
}

