#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

int main() {
    int N, *XY, i, j;
    double x, y, a, b, D[1000], ans;

    // Read input
    scanf("%d", &N);
    XY = (int*)malloc(2 * N * sizeof(int));
    for (i = 0; i < 2 * N; i++) {
        scanf("%d", &XY[i]);
    }

    // Process each point
    for (i = 0; i < N; i++) {
        x = XY[2 * i];
        y = XY[2 * i + 1];

        // Calculate angles
        int k = 0;
        for (j = 0; j < N; j++) {
            if (j != i) {
                D[k++] = atan2(XY[2 * j] - x, XY[2 * j + 1] - y);
            }
        }

        // Sort angles
        qsort(D, N - 1, sizeof(double), (int (*)(const void *, const void *))compare);

        // Add 2*PI to the last element
        D[N - 1] = D[N - 1] + 2 * PI;

        // Find the maximum angle difference
        ans = 0;
        for (j = 0; j < N - 1; j++) {
            a = D[j];
            b = D[j + 1];
            if (b - a >= PI) {
                ans = (b - a) - PI;
                break;
            }
        }

        // Print the result
        printf("%.10f\n", ans / (2 * PI));
    }

    // Free allocated memory
    free(XY);

    return 0;
}

int compare(const void *a, const void *b) {
    double diff = (*(double*)a - *(double*)b);
    return (diff > 0) - (diff < 0);
}
