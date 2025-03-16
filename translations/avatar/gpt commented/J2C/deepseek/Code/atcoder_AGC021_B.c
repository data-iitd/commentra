#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(double*)a - *(double*)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int x[N], y[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }

    for (int i = 0; i < N; ++i) {
        double thetas[N - 1];
        int theta_index = 0;

        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            thetas[theta_index++] = atan2(y[j] - y[i], x[j] - x[i]);
        }

        qsort(thetas, N - 1, sizeof(double), compare);

        for (int k = 0; k < N - 1; ++k) {
            thetas[k + N - 1] = thetas[k] + 2 * M_PI;
        }

        double ans = 0;
        for (int k = 0; k < 2 * (N - 1); ++k) {
            ans = fmax(ans, thetas[k + 1] - thetas[k] - M_PI);
        }

        printf("%.12f\n", ans / (2 * M_PI));
    }

    return 0;
}
