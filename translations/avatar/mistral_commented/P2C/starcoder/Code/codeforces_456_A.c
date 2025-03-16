
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, a, b, c;
    scanf("%d", &n);
    int m[n][2];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (m[i][1] < m[j][1])
            {
                a = m[i][0];
                b = m[i][1];
                c = m[j][0];
                m[i][0] = c;
                m[i][1] = b;
                m[j][0] = a;
                m[j][1] = b;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (m[i][1] > m[0][1])
        {
            printf("Happy Alex\n");
            break;
        }
    }
    if (i == n)
    {
        printf("Poor Alex\n");
    }
    return 0;
}

