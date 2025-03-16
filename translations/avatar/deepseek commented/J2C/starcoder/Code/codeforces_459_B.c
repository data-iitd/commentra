#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    int N;
    scanf("%d", &N);
    int A[N];
    for(int n = 0; n < N; n++) {
        scanf("%d", &A[n]);
    }
    qsort(A, N, sizeof(int), cmpfunc);
    int min = A[0];
    int max = A[N-1];
    long mins = 0;
    long maxs = 0;
    for(int value = 0; value < N; value++) {
        if(A[value] == min) {
            mins++;
        }
        if(A[value] == max) {
            maxs++;
        }
    }
    if(min == max) {
        printf("%d %ld\n", max - min, mins * (mins - 1) / 2);
    } else {
        printf("%d %ld\n", max - min, mins * maxs);
    }
    return 0;
}

int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

