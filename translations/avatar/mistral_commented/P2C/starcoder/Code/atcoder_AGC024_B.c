
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int *P = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &P[i]);
    }
    int *a = (int *)malloc((N + 1) * sizeof(int));
    for (int i = 0; i < N + 1; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        a[P[i]] = i;
    }
    int tmp = 1;
    int max_len = 1;
    for (int i = 1; i < N; i++)
    {
        if (a[i] < a[i + 1])
        {
            tmp += 1;
            max_len = max(max_len, tmp);
        }
        else
        {
            tmp = 1;
        }
    }
    int ans = N - max_len;
    printf("%d", ans);
    return 0;
}

