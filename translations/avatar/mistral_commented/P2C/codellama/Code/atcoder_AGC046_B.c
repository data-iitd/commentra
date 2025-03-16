
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, C, D;
    int **d;
    int i, j;
    int m = 1000000007;

    scanf("%d %d %d %d", &A, &B, &C, &D);

    d = (int **)malloc((C + 1) * sizeof(int *));
    for (i = 0; i < C + 1; i++)
    {
        d[i] = (int *)malloc((D + 1) * sizeof(int));
    }

    for (i = 0; i < C + 1; i++)
    {
        for (j = 0; j < D + 1; j++)
        {
            d[i][j] = 0;
        }
    }

    d[A][B] = 1;

    for (i = A; i <= C; i++)
    {
        for (j = B; j <= D; j++)
        {
            d[i][j] += (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1)) % m;
        }
    }

    printf("%d", d[C][D]);

    return 0;
}

