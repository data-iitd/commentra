
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, result = 0;
    scanf("%d", &n);
    int *h = (int *)malloc(n * sizeof(int));
    int *g = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
        scanf("%d", &g[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (h[i] == g[j])
            {
                result++;
            }
        }
    }
    printf("%d", result);
    return 0;
}

