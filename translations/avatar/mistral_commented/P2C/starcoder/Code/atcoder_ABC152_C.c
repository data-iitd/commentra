#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, a = 1, pos = 0;
    scanf("%d", &N);
    int *n = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
        scanf("%d", &n[i]);
    for (i = 1; i < N; i++)
    {
        if (n[pos] > n[i])
        {
            a++;
            pos = i;
        }
    }
    printf("%d", a);
    return 0;
}
