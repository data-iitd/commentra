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
    int l[n][n];
    int rem[n];
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            l[j][count] = j;
            count++;
        }
        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < pow(2, j); k++)
            {
                int ca = 0;
                for (int ii = 0; ii < j; ii++)
                {
                    ca += c[l[k][ii]][i];
                }
                if (ca < x)
                {
                    rem[count] = k;
                    count++;
                }
            }
            for (int k = 0; k < count; k++)
            {
                for (int ii = k; ii < count - 1; ii++)
                {
                    l[k][ii] = l[k][ii + 1];
                }
            }
            count--;
        }
        if (count == 0)
        {
            printf("-1\n");
            break;
        }
        for (int j = 0; j < count; j++)
        {
            int ca = 0;
            for (int ii = 0; ii < count; ii++)
            {
                ca += c[l[j][ii]][0];
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
    }
    printf("%d\n", ans);
    return 0;
}

