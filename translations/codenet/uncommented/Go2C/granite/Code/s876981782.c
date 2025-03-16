
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    double *values = (double *)malloc(sizeof(double) * N);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &values[i]);
    }

    qsort(values, N, sizeof(double), compare);
    double generated = 0;
    for (int i = 0; i < N - 1; i++) {
        generated = (values[i] + values[i + 1]) / 2;
        values[i + 1] = generated;
    }

    printf("%.1f\n", generated);
    free(values);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(double *)a - *(double *)b);
}

