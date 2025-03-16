#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i, j, p, l;
    int *M;
    scanf("%d %d", &n, &k);
    M = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &M[i]);
    for (j = 0; j < n; j++)
    {
        for (p = 0; p < n; p++)
        {
            if (M[p] == 0)
            {
                printf("%d ", p + 1);
                break;
            }
        }
        for (l = p - k; l < p; l++)
            M[l]--;
        M[p]--;
    }
    free(M);
    return 0;
}

