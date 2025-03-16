#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, cnt = 0;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        A[i] = (i * N + scanf("%d")) % N;
    }
    qsort(A, N, sizeof(int), compare);
    for (i = 0; i < N; i++)
    {
        if ((A[i] % N) % 2!= i % 2)
        {
            cnt++;
        }
    }
    printf("%d\n", cnt / 2);
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

