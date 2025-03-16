#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n, i, j, k, l, m, pn, qn, p[100], q[100], orig[100][100];
    char str[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            orig[i][j] = j + 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &p[j]);
        }
        pn = 0;
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (p[j] == orig[j][k])
                {
                    pn = pn + k;
                }
            }
        }
        printf("%d\n", pn);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &q[j]);
        }
        qn = 0;
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (q[j] == orig[j][k])
                {
                    qn = qn + k;
                }
            }
        }
        printf("%d\n", qn);
    }

    printf("%d", abs(pn - qn));

    return 0;
}

