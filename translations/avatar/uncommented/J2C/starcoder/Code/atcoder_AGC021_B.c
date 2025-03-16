#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(int argc, char **argv) {
    int N;
    scanf("%d", &N);
    int x[N], y[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }
    for (int i = 0; i < N; ++i) {
        double thetas[N];
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            thetas[j] = atan2(y[j] - y[i], x[j] - x[i]);
        }
        qsort(thetas, N, sizeof(double), cmp);
        thetas[N] = thetas[0] + 2 * M_PI;
        double ans = 0;
        for (int k = 0; k < N - 1; ++k) {
            ans = fmax(ans, thetas[k + 1] - thetas[k] - M_PI);
        }
        printf("%.10lf\n", ans / (M_PI * 2));
    }
    return 0;
}

int cmp(const void *a, const void *b) {
    return *(double *)a - *(double *)b;
}

