#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    double XY[N][2];
    for (int i = 0; i < N; i++)
        scanf("%lf%lf", &XY[i][0], &XY[i][1]);
    for (int i = 0; i < N; i++) {
        double D[N];
        for (int j = 0; j < N; j++)
            D[j] = atan2(XY[j][0] - XY[i][0], XY[j][1] - XY[i][1]);
        double ans = 0;
        for (int j = 0; j < N; j++) {
            if (j == 0)
                D[j] += 2 * M_PI;
            else
                D[j] += 2 * M_PI;
            if (D[j] - D[j - 1] >= M_PI)
                ans = (D[j] - D[j - 1]) - M_PI;
        }
        printf("%.10lf\n", ans / (2 * M_PI));
    }
    return 0;
}

