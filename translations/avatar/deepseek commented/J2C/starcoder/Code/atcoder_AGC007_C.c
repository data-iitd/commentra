
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>

#define MAX_PRECISION 20

int main(int argc, char **argv)
{
    double N, d, x;
    scanf("%lf %lf %lf", &N, &d, &x);

    double ans = 0.0;
    while (N > 0.5) {
        double adnum = d + x * (N - 0.5);
        ans += adnum;

        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;
        --N;
    }

    printf("%.20lf\n", ans);
    return 0;
}

