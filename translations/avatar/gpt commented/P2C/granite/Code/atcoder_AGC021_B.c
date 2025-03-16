
#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    double X[N], Y[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf%lf", &X[i], &Y[i]);
    }
    for (int i = 0; i < N; i++) {
        double D[N - 1];
        for (int j = 0, k = 0; j < N; j++) {
            if (i == j) continue;
            D[k++] = atan2(Y[j] - Y[i], X[j] - X[i]);
        }
        D[N - 2] += 2 * M_PI;
        qsort(D, N - 1, sizeof(double), cmp);
        double ans = 0;
        for (int j = 0; j < N - 1; j++) {
            if (D[j] + M_PI <= D[j + 1]) {
                ans = fmax(ans, D[j + 1] - D[j] - M_PI);
            }
        }
        printf("%.10f\n", ans / (2 * M_PI));
    }
    return 0;
}

int cmp(const void *a, const void *b) {
    return (* (double *) a - * (double *) b);
}

