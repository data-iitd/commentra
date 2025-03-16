#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(float*)a - *(float*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    float fractional_arr[n];
    int o = 0;
    for (int i = 0; i < n; i++) {
        float frac = arr[i] - (int)arr[i];
        if (frac != 0) {
            fractional_arr[o++] = frac;
        }
    }
    qsort(fractional_arr, o, sizeof(float), compare);
    float arr_sum = 0;
    for (int i = 0; i < n; i++) {
        arr_sum += arr[i];
    }
    float res = 2e9;
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            float temp_res = fabs(i - arr_sum);
            if (temp_res < res) {
                res = temp_res;
            }
        }
    }
    printf("%.3f\n", res);
    return 0;
}
