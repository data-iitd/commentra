
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    int A_[N];
    for (int i = 0; i < N; i++)
    {
        A_[i] = A[i];
    }
    int A__[N];
    for (int i = 0; i < N; i++)
    {
        A__[i] = A_[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        printf("%d ", A__[i]);
    }
    printf("%d", A__[N - 1]);
    return 0;
}

