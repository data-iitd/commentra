#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

int main() {
    int N;
    scanf("%d", &N);

    double XY[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%lf %lf", &XY[i][0], &XY[i][1]);
    }

    double ans = 0.0;

    for (int i = 0; i < N; i++) {
        double D[N-1];
        int k = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                D[k++] = atan2(XY[j][0] - XY[i][0], XY[j][1] - XY[i][1]);
            }
        }

        // Sort the angles
        qsort(D, N-1, sizeof(double), (int (*)(const void *, const void *))compare);

        // Append the angle wrapped around if it's greater than PI
        for (int j = 0; j < N-1; j++) {
            D[j + (N-1)] = D[j] + 2 * PI;
        }

        // Calculate the total area of the sectors
        for (int j = 0; j < 2*(N-1); j++) {
            double angle = D[j + 1] - D[j];
            if (angle >= PI) {
                ans += (angle - PI);
            }
        }
    }

    // Print the answer
    printf("%.12f\n", ans / (2 * PI));

    return 0;
}

int compare(const void *a, const void *b) {
    double diff = (*(double *)a - *(double *)b);
    return (diff > 0) - (diff < 0);
}
