#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);

    int A;
    int i;
    int idorder[N+1];
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &A);
        idorder[A] = i;
    }

    for (i = 1; i <= N; i++)
    {
        printf("%d ", idorder[i]);
    }

    return 0;
}

