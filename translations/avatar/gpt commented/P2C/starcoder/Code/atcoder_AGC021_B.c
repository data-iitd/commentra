#include <math.h>
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    double XY[N][2];
    for (int i = 0; i < N; i++)
        scanf("%lf%lf", &XY[i][0], &XY[i][1]);
    for (int i = 0; i < N; i++) {
        double x = XY[i][0], y = XY[i][1];
        double D[N];
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            double X = XY[j][0], Y = XY[j][1];
            D[j] = atan2(X - x, Y - y);
        }
        double ans = 0;
        for (int j = 0; j < N - 1; j++) {
            double a = D[j], b = D[j + 1];
            if (b - a >= M_PI) ans += (b - a) - M_PI;
        }
        printf("%.10lf\n", ans / (2 * M_PI));
    }
    return 0;
}

