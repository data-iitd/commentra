#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, total = 0;
    scanf("%d", &N);
    int *a = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
        total = total ^ a[i];
    }
    for (i = 0; i < N; i++)
    {
        printf("%d ", a[i] ^ total);
    }
    printf("\n");
    free(a);
    return 0;
}
