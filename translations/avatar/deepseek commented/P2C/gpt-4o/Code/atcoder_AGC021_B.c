#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main() {
    // Step 1: Reading Input
    int N;
    scanf("%d", &N);
    double *XY = malloc(N * 2 * sizeof(double));
    for (int i = 0; i < N * 2; i++) {
        scanf("%lf", &XY[i]);
    }

    // Step 2: Processing Coordinates
    double *angles = malloc((N - 1) * sizeof(double));

    // Step 3: Calculating Angles
    for (int i = 0; i < N; i++) {
        int angle_count = 0;
        for (int j = 0; j < N; j++) {
            if (j != i) {
                double x = XY[i * 2];
                double y = XY[i * 2 + 1];
                double X = XY[j * 2];
                double Y = XY[j * 2 + 1];
                angles[angle_count++] = atan2(X - x, Y - y);
            }
        }

        // Step 4: Handling Circular Angles
        qsort(angles, angle_count, sizeof(double), compare);
        angles[angle_count] = angles[0] + 2 * M_PI;

        // Step 5: Finding the Maximum Gap
        double ans = 0;
        for (int k = 0; k < angle_count; k++) {
            double gap = angles[k + 1] - angles[k];
            if (gap >= M_PI) {
                ans = fmax(ans, gap - M_PI);
            }
        }

        // Step 6: Calculating the Fraction
        printf("%lf\n", ans / (2 * M_PI));
    }

    // Free allocated memory
    free(XY);
    free(angles);

    return 0;
}

// <END-OF-CODE>
