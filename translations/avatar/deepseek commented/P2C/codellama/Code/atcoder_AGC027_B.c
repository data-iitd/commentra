#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, X, *A, *S, k, j, i, ans;
    scanf("%d %d", &N, &X);
    A = (int *)malloc(N * sizeof(int));
    S = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    S[0] = A[0];
    for (i = 1; i < N; i++)
        S[i] = S[i - 1] + A[i];
    ans = 1000000000;
    for (k = 1; k <= N / 2; k++)
    {
        int E = k * X + 2 * (S[N - 2 * k - 1] - S[N - k - 1]);
        ans = min(ans, E);
    }
    printf("%d", ans + N * X + 5 * S[N - 1]);
    return 0;
}

