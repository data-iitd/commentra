
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, a, pos;
    scanf("%d", &N);
    int *n = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n[i]);
    }
    a = 1;
    pos = 0;
    for (int i = 1; i < N; i++)
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

