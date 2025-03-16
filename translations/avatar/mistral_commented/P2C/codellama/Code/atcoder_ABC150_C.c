#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    int orig[n][n];
    int p[n];
    int q[n];
    int pn, qn;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            orig[i][j] = j + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i] == orig[j][i])
            {
                pn = j;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (q[i] == orig[j][i])
            {
                qn = j;
            }
        }
    }

    printf("%d", abs(pn - qn));

    return 0;
}

