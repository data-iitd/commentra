#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int N, i, j, gcd;
    int *A;

    scanf("%d", &N);

    A = (int *)malloc(N * sizeof(int));

    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    gcd = A[0];

    for (i = 1; i < N; i++)
        gcd = gcd(gcd, A[i]);

    printf("%d", gcd);

    free(A);

    return 0;
}

