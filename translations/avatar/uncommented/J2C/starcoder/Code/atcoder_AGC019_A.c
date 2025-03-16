#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    long Q, H, S, D, N;
    scanf("%ld %ld %ld %ld %ld", &Q, &H, &S, &D, &N);
    long onePrice = (long)fmin(fmin(Q * 4, H * 2), S);
    if (onePrice <= D / 2) {
        printf("%ld\n", N * onePrice);
    } else {
        printf("%ld\n", (N / 2) * D + (N % 2) * onePrice);
    }
    return 0;
}

