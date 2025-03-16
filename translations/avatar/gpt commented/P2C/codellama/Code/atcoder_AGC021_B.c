#include <stdio.h>
#include <math.h>

int main() {
    int N, x, y, i, j, X, Y;
    double ans, a, b;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        for (j = 0; j < N; j++) {
            scanf("%d %d", &X, &Y);
            if (j != i) {
                D[j] = atan2(X - x, Y - y);
            }
        }
        D[N] = D[0] + 2 * pi;
        ans = 0;
        for (j = 0; j < N; j++) {
            a = D[j];
            b = D[j + 1];
            if (b - a >= pi) {
                ans = (b - a) - pi;
            }
        }
        printf("%.10f\n", ans / (2 * pi));
    }
    return 0;
}
