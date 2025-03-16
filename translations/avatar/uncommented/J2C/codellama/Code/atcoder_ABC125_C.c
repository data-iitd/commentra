
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N;
    int *A;
    int *M;
    int *L;
    int *R;
    int i;
    int tmp;
    int r;

    scanf("%d", &N);
    A = (int *)malloc(N * sizeof(int));
    M = (int *)malloc(N * sizeof(int));
    L = (int *)malloc(N * sizeof(int));
    R = (int *)malloc(N * sizeof(int));

    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    L[0] = A[0];
    for (i = 1; i < N; i++)
    {
        L[i] = gcd(L[i - 1], A[i]);
    }

    R[N - 1] = A[N - 1];
    for (i = N - 2; i >= 0; i--)
    {
        R[i] = gcd(R[i + 1], A[i]);
    }

    int answer = max(L[N - 2], R[1]);
    for (i = 1; i < N - 1; i++)
    {
        answer = max(answer, gcd(L[i - 1], R[i + 1]));
    }

    printf("%d\n", answer);

    free(A);
    free(M);
    free(L);
    free(R);

    return 0;
}

int gcd(int a, int b)
{
    int tmp;
    if (b > a)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (b == 0)
    {
        return a;
    }
    r = -1;
    do
    {
        r = a % b;
        a = b;
        b = r;
    } while (r != 0);
    return a;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

