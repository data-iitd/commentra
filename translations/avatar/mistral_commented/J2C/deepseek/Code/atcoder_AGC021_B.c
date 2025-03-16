#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

double angle_between(Point a, Point b) {
    return atan2(b.y - a.y, b.x - a.x);
}

int main() {
    int N;
    scanf("%d", &N);

    Point points[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    double thetas[N][N - 1];
    for (int i = 0; i < N; ++i) {
        int theta_count = 0;
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                thetas[i][theta_count++] = angle_between(points[i], points[j]);
            }
        }

        // Sorting the angles
        qsort(thetas[i], theta_count, sizeof(double), (int (*)(const void *, const void *))compare);

        // Adding the angle between the last point and the first point (wrapped around 2π)
        thetas[i][theta_count] = thetas[i][0] + 2 * M_PI;
    }

    double ans = 0;
    for (int k = 0; k < N - 1; ++k) {
        double diff = thetas[k][k + 1] - thetas[k][k] - M_PI;
        if (diff > ans) {
            ans = diff;
        }
    }

    printf("%.12f\n", ans / (2 * M_PI));
    return 0;
}

int compare(const void *a, const void *b) {
    double diff = (*(double *)a - *(double *)b);
    return (diff > 0) - (diff < 0);
}
