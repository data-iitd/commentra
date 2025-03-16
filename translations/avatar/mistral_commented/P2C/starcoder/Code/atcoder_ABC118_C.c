#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    int gcd = A[0];
    for (int i = 1; i < N; i++)
    {
        gcd = gcd(gcd, A[i] % gcd);
    }
    printf("%d", gcd);
    return 0;
}
