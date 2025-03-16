#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    double XY[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%lf%lf", &XY[i][0], &XY[i][1]);
    }
    double D[N];
    for (int i = 0; i < N; i++) {
        double x = XY[i][0], y = XY[i][1];
        D[i] = atan2(XY[0][0] - x, XY[0][1] - y);
        for (int j = 1; j < N; j++) {
            double X = XY[j][0], Y = XY[j][1];
            double d = atan2(X - x, Y - y);
            if (d < D[i]) {
                D[i] = d;
            }
        }
        if (D[i] < 0) {
            D[i] += 2 * M_PI;
        }
    }
    double ans = 0;
    for (int i = 0; i < N - 1; i++) {
        double a = D[i], b = D[i + 1];
        if (b - a >= M_PI) {
            ans += (b - a) - M_PI;
        }
    }
    printf("%.10lf\n", ans / (2 * M_PI));
    return 0;
}

