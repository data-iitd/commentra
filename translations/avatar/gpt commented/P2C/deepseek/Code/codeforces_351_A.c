#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (floor(arr[i]) != arr[i]) {
            count++;
        }
    }

    float fractional_parts[count];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (floor(arr[i]) != arr[i]) {
            fractional_parts[j++] = arr[i] - floor(arr[i]);
        }
    }

    int o = 2 * n - count;

    float arr_sum = 0;
    for (int i = 0; i < count; i++) {
        arr_sum += fractional_parts[i];
    }

    float res = 2e9;

    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            res = fmin(res, fabs(i - arr_sum));
        }
    }

    printf("%.3f\n", res);

    return 0;
}
