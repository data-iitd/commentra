
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int *A;
    int mn, mx;

    scanf("%d", &N);
    A = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    mn = N + 1;
    mx = -1;
    for (i = 0; i < N; i++)
    {
        if (i + 1 != A[i])
        {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    if (mx == -1)
    {
        printf("0 0\n");
    }
    else
    {
        A = (int *)realloc(A, (mn + 1) * sizeof(int));
        for (i = 0; i < mn; i++)
        {
            A[i] = A[i + 1];
        }
        A = (int *)realloc(A, (mx + 1) * sizeof(int));
        for (i = mx + 1; i < N; i++)
        {
            A[i] = A[i - 1];
        }
        if (sorted(A, N) == A)
        {
            printf("%d %d\n", mn + 1, mx + 1);
        }
        else
        {
            printf("0 0\n");
        }
    }
    free(A);
    return 0;
}

