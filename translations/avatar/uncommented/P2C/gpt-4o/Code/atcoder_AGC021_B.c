#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int *XY = malloc(2 * N * sizeof(int));
    for (int i = 0; i < 2 * N; i++) {
        scanf("%d", &XY[i]);
    }

    for (int i = 0; i < N; i++) {
        double *D = malloc((N - 1) * sizeof(double));
        int index = 0;

        for (int j = 0; j < N; j++) {
            if (j != i) {
                double x = XY[i * 2];
                double y = XY[i * 2 + 1];
                double X = XY[j * 2];
                double Y = XY[j * 2 + 1];
                D[index++] = atan2(X - x, Y - y);
            }
        }

        // Sort D
        qsort(D, N - 1, sizeof(double), (int (*)(const void *, const void *))compare);

        // Append the first element + 2 * pi
        D[index] = D[0] + 2 * M_PI;

        double ans = 0;
        for (int k = 0; k < index; k++) {
            double a = D[k];
            double b = D[k + 1];
            if (b - a >= M_PI) {
                ans = (b - a) - M_PI;
            }
        }

        printf("%lf\n", ans / (2 * M_PI));
        free(D);
    }

    free(XY);
    return 0;
}

int compare(const double *a, const double *b) {
    return (*a > *b) - (*a < *b);
}
