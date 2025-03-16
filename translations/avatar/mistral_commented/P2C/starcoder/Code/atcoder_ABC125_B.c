#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, X, Y, ans = 0;
    scanf("%d", &N);
    int *V = (int *)malloc(N * sizeof(int));
    int *C = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
        scanf("%d", &C[i]);
    }
    for (i = 0; i < N; i++)
    {
        if (V[i] - C[i] > 0)
        {
            X = V[i];
            Y = C[i];
            ans += X - Y;
        }
    }
    printf("%d\n", ans);
    return 0;
}
