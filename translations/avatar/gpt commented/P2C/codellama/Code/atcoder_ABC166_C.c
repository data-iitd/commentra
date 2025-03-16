#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, a, b, c = 0;
    scanf("%d %d", &n, &m);
    int *p = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        p[i] = i + 1;
    int *h = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &h[i]);
    int **path = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        path[i] = (int *)malloc(n * sizeof(int));
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        path[a - 1][b - 1] = 1;
        path[b - 1][a - 1] = 1;
    }
    for (i = 0; i < n; i++)
    {
        int f = 0;
        for (j = 0; j < n; j++)
        {
            if (h[i] <= h[j] && path[i][j] == 1)
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
            c++;
    }
    printf("%d", c);
    return 0;
}
