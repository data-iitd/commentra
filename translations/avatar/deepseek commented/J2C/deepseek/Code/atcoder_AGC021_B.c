#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} Point;

double angle_between(Point p1, Point p2) {
    return atan2(p2.y - p1.y, p2.x - p1.x);
}

int main() {
    int N;
    scanf("%d", &N);

    Point points[N];
    for (int i = 0; i < N; ++i) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    for (int i = 0; i < N; ++i) {
        double thetas[N - 1];
        int theta_count = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue; // Skip the point itself
            thetas[theta_count++] = angle_between(points[i], points[j]);
        }

        // Sort the angles
        qsort(thetas, theta_count, sizeof(double), (int (*)(const void *, const void *))compare);

        // Add 2*π to the last angle to handle the wrap-around
        double thetas_with_wrap[theta_count + 1];
        for (int k = 0; k < theta_count; ++k) {
            thetas_with_wrap[k] = thetas[k];
        }
        thetas_with_wrap[theta_count] = thetas[0] + 2 * M_PI;

        // Find the maximum difference between consecutive angles, subtract π, and divide by 2π to get the fraction of the circle
        double ans = 0;
        for (int k = 0; k < theta_count; ++k) {
            double diff = thetas_with_wrap[k + 1] - thetas_with_wrap[k] - M_PI;
            if (diff > ans) {
                ans = diff;
            }
        }

        // Print the result
        printf("%.12f\n", ans / (2 * M_PI));
    }

    return 0;
}

int compare(const void *a, const void *b) {
    double diff = (*(double *)a - *(double *)b);
    return (diff > 0) - (diff < 0);
}
