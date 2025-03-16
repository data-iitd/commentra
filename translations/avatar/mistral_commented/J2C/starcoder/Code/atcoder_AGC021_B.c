#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
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

        for (int k = 0; k < N; ++k) {
            thetas[k] += 2 * M_PI;
        }

        double ans = 0;
        for (int k = 0; k < N - 1; ++k) {
            ans = fmax(ans, thetas[k + 1] - thetas[k] - M_PI);
        }

        printf("%.10lf\n", ans / (2 * M_PI));
    }

    return 0;
}

