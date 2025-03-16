#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <omp.h>

#define MAX_N 1000000

int main(int argc, char *argv[])
{
    int N;
    scanf("%d", &N);
    int A[MAX_N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    int A_[MAX_N];
    for (int i = 0; i < N; i++)
    {
        A_[i] = A[i];
    }
    int A__[MAX_N];
    for (int i = 0; i < N - 1; i++)
    {
        A__[i] = A_[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        printf("%d ", A__[i]);
    }
    printf("%d", A__[N - 2]);
    return 0;
}
