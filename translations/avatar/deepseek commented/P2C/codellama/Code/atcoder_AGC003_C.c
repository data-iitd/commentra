#include <stdio.h>

int main()
{
    int N, i, cnt = 0;
    scanf("%d", &N);
    int A[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    for (i = 0; i < N; i++)
    {
        if ((A[i] % N) % 2 != i % 2)
        {
            cnt++;
        }
    }
    printf("%d", cnt / 2);
    return 0;
}
