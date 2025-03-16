#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int N;
    scanf("%d", &N);
    int A[5];
    for(int i = 0; i < 5; i++)
        scanf("%d", &A[i]);
    printf("%d", (int)ceil(N/min(A))+4);
    return 0;
}
