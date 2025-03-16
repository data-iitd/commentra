#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    if (*(float *)a < *(float *)b) return -1;
    if (*(float *)a > *(float *)b) return 1;
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    float *values = (float *)malloc(N * sizeof(float));
    for (int i = 0; i < N; i++) {
        scanf("%f", &values[i]);
    }

    qsort(values, N, sizeof(float), compare);
    float generated;
    for (int i = 0; i < N - 1; i++) {
        generated = (values[i] + values[i + 1]) / 2;
        values[i + 1] = generated;
    }

    printf("%f\n", generated);
    free(values);
    return 0;
}

// <END-OF-CODE>
