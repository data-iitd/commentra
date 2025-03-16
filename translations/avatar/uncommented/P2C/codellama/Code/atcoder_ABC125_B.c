#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N, i, j, X, Y;
    int *V, *C, *list;
    scanf("%d", &N);
    V = (int *)malloc(N * sizeof(int));
    C = (int *)malloc(N * sizeof(int));
    list = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", &C[i]);
    }
    list[0] = 0;
    for (i = 0; i < N; i++)
    {
        if (V[i] - C[i] > 0)
        {
            X = V[i];
            Y = C[i];
            list[i + 1] = X - Y;
        }
    }
    printf("%d", sum(list));
    return 0;
}