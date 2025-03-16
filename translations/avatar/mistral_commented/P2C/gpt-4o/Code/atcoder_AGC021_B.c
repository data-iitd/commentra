#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main() {
    int N;
    scanf("%d", &N);
    
    double *angles = malloc(N * sizeof(double));
    double *x = malloc(N * sizeof(double));
    double *y = malloc(N * sizeof(double));

    for (int i = 0; i < N; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double ans = 0;

    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (j != i) {
                angles[count++] = atan2(x[j] - x[i], y[j] - y[i]);
            }
        }

        qsort(angles, count, sizeof(double), compare);
        angles[count] = angles[0] + 2 * M_PI; // Wrap around

        for (int k = 0; k < count; k++) {
            double a = angles[k];
            double b = angles[k + 1];
            if (b - a >= M_PI) {
                ans += (b - a) - M_PI;
            }
        }
    }

    printf("%lf\n", ans / (2 * M_PI));

    free(angles);
    free(x);
    free(y);
    return 0;
}

// <END-OF-CODE>
