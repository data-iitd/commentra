#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), compare);
    int min = A[0];
    int max = A[N - 1];
    long mins = 0;
    long maxs = 0;
    for(int i = 0; i < N; i++)
    {
        if(A[i] == min)
            mins++;
        if(A[i] == max)
            maxs++;
    }
    if(min == max)
    {
        printf("%d %ld\n", max - min, mins * (mins - 1) / 2);
    }
    else
    {
        printf("%d %ld\n", max - min, mins * maxs);
    }
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

