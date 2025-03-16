#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, i, j, a, b, c = 0;
    int *p, *h, *path;
    scanf("%d %d", &n, &m);
    p = (int *)malloc(sizeof(int) * (n + 1));
    h = (int *)malloc(sizeof(int) * (n + 1));
    path = (int *)malloc(sizeof(int) * (n + 1));
    for (i = 0; i < n + 1; i++)
    {
        p[i] = i + 1;
    }
    for (i = 0; i < n + 1; i++)
    {
        scanf("%d", &h[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        path[a] = b;
        path[b] = a;
    }
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < n + 1; j++)
        {
            if (h[i] <= h[j])
            {
                c++;
                break;
            }
        }
    }
    printf("%d", c);
    return 0;
}

