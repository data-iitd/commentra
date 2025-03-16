#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    int x, y;
    int **black;
    int i, j;

    scanf("%d %d", &N, &M);
    black = (int **)malloc((N + 2) * sizeof(int *));
    for (i = 0; i < N + 2; i++)
        black[i] = (int *)malloc((N + 2) * sizeof(int));

    for (i = 0; i < N + 2; i++)
        for (j = 0; j < N + 2; j++)
            black[i][j] = 0;

    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &x, &y);
        for (j = x - 1; j <= x + 1; j++)
            for (i = y - 1; i <= y + 1; i++)
                black[j][i]++;
    }

    for (i = 0; i < N + 2; i++)
        free(black[i]);
    free(black);

    return 0;
}

