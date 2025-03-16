
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
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            D[i] = atan2(XY[j][0] - XY[i][0], XY[j][1] - XY[i][1]);
        }
        D[i] += 2 * M_PI;
    }
    double ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (D[j] - D[i] >= M_PI) {
                ans += D[j] - D[i] - M_PI;
            }
        }
    }
    printf("%.10lf\n", ans / (2 * M_PI));
    return 0;
}
