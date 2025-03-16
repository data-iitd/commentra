#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int gcd = 0;
    for (int i = 0; i < N; i++)
    {
        gcd = __gcd(gcd, A[i]);
    }
    printf("%d\n", gcd);
    return 0;
}

