
#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    double XY[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%lf %lf", &XY[i][0], &XY[i][1]);
    }
    for (int i = 0; i < N; i++) {
        double D[N - 1];
        for (int j = 0, k = 0; j < N; j++) {
            if (i == j) continue;
            D[k++] = atan2(XY[j][0] - XY[i][0], XY[j][1] - XY[i][1]);
        }
        D[N - 2] += 2 * M_PI;
        double ans = 0;
        for (int j = 0; j < N - 1; j++) {
            if (D[j + 1] - D[j] >= M_PI) {
                ans = fmax(ans, D[j + 1] - D[j] - M_PI);
            }
        }
        printf("%.10lf\n", ans / (2 * M_PI));
    }
    return 0;
}
//END-OF-CODE