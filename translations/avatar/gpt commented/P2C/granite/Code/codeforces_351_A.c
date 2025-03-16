
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    float *arr = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    float *frac = (float *)malloc((n + 1) * sizeof(float));
    int count = 0;
    for (int i = 0; i < n; i++) {
        float f = arr[i] - (int)arr[i];
        if (f!= 0) {
            frac[count++] = f;
        }
    }

    qsort(frac, count, sizeof(float), cmp);

    int o = 2 * n - count;
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += frac[i];
    }

    float res = 1e9;
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            res = fminf(res, fabs(i - sum));
        }
    }

    printf("%.3f\n", res);

    free(arr);
    free(frac);

    return 0;
}

int cmp(const void *a, const void *b) {
    return *(float *)a - *(float *)b;
}

