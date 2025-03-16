#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} Point;

double angle_diff(double a, double b) {
    double diff = fmod(a - b + 2 * M_PI, 2 * M_PI);
    return diff < 0 ? diff + 2 * M_PI : diff;
}

int compare(const void *a, const void *b) {
    double diff = *(double *)a - *(double *)b;
    return diff > 0 ? 1 : (diff < 0 ? -1 : 0);
}

int main() {
    int N;
    scanf("%d", &N);
    Point points[N];
    for (int i = 0; i < N; ++i) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    for (int i = 0; i < N; ++i) {
        double thetas[N];
        int theta_count = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            thetas[theta_count++] = atan2(points[j].y - points[i].y, points[j].x - points[i].x);
        }

        qsort(thetas, theta_count, sizeof(double), compare);

        for (int k = 0; k < theta_count; ++k) {
            thetas[theta_count + k] = thetas[k] + 2 * M_PI;
        }

        double ans = 0;
        for (int k = 0; k < theta_count; ++k) {
            double diff = angle_diff(thetas[k + 1], thetas[k]);
            if (diff > ans) {
                ans = diff;
            }
        }

        printf("%.12f\n", (ans - M_PI) / (2 * M_PI));
    }

    return 0;
}
