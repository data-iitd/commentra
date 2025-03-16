#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, X, Y;
    int *V, *C;
    int *list;
    int ans;

    scanf("%d", &N);
    V = (int *) malloc(N * sizeof(int));
    C = (int *) malloc(N * sizeof(int));
    list = (int *) malloc(N * sizeof(int));

    for(i=0; i<N; i++)
    {
        scanf("%d", &V[i]);
        scanf("%d", &C[i]);
    }

    for(i=0; i<N; i++)
    {
        if(V[i] - C[i] > 0)
        {
            X = V[i];
            Y = C[i];
            list[i] = X - Y;
        }
    }

    ans = 0;
    for(i=0; i<N; i++)
    {
        ans += list[i];
    }

    printf("%d", ans);

    return 0;
}
