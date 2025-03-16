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
    long N, A, B, k;
    scanf("%ld %ld %ld", &N, &A, &B);
    if (1 <= N && N <= pow(10, 18) && 0 <= A && 0 <= B && 0 < A + B && A + B <= pow(10, 18))
    {
        if (A + B <= N)
        {
            k = N / (A + B);
            if (N - k * (A + B) > A)
            {
                printf("%ld\n", A * k + (N - k * (A + B)) - (N - (k * (A + B) + A)));
            }
            else
            {
                printf("%ld\n", A * k + (N - k * (A + B)));
            }
        }
        else if (A + B > N && A <= N)
        {
            printf("%ld\n", A);
        }
        else
        {
            printf("%ld\n", N);
        }
    }
    return 0;
}

