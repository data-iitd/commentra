
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, r, n, m;
    int *L;
    scanf("%d", &n);
    L = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        for (j = 0; j < k; j++)
        {
            L[i] = r;
            r++;
        }
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &j);
        printf("%d\n", L[j - 1]);
    }
    free(L);
    return 0;
}

