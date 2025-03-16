#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    double *arr = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    double *fractional_parts = (double *)malloc(n * sizeof(double));
    int count = 0;

    for (int i = 0; i < n; i++) {
        double fractional_part = arr[i] - (int)arr[i];
        if (fractional_part != 0) {
            fractional_parts[count++] = fractional_part;
        }
    }

    qsort(fractional_parts, count, sizeof(double), compare);
    
    int o = 2 * n - count;
    double arr_sum = 0;
    for (int i = 0; i < count; i++) {
        arr_sum += fractional_parts[i];
    }

    double res = 2e9;
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            res = fmin(res, fabs(i - arr_sum));
        }
    }

    printf("%.3f\n", res);

    free(arr);
    free(fractional_parts);
    return 0;
}

// <END-OF-CODE>
