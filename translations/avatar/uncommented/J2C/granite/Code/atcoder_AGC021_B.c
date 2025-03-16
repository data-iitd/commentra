
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    int x[N], y[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 0; i < N; ++i) {
        double thetas[N - 1];
        int k = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            thetas[k++] = atan2(y[j] - y[i], x[j] - x[i]);
        }
        qsort(thetas, N - 1, sizeof(double), cmp);
        thetas[N - 2] += 2 * M_PI;
        double ans = 0;
        for (int k = 0; k < N - 1; ++k) {
            ans = fmax(ans, thetas[k + 1] - thetas[k] - M_PI);
        }
        printf("%.10f\n", ans / (2 * M_PI));
    }
    return 0;
}

