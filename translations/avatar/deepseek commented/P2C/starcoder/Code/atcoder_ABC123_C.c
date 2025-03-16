
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, A[5];
    scanf("%d", &N);
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("%d", ceil(N / min(A)) + 4);
    return 0;
}

