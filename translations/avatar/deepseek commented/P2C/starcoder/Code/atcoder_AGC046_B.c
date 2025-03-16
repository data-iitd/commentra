#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int A, B, C, D, m = 998244353;
    int **d = (int **)malloc(sizeof(int *) * (C + 1));
    for (int i = 0; i <= C; i++)
        d[i] = (int *)malloc(sizeof(int) * (D + 1));
    for (int i = 0; i <= C; i++)
        for (int j = 0; j <= D; j++)
            d[i][j] = 0;
    d[A][B] = 1;
    for (int i = A; i <= C; i++)
        for (int j = B; j <= D; j++)
            d[i][j] += (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1)) % m;
    printf("%d\n", d[C][D]);
    return 0;
}

