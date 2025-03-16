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

    float temp[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (fmod(arr[i], 1) != 0) {
            temp[j++] = fmod(arr[i], 1);
        }
    }

    for (int i = 0; i < j - 1; i++) {
        for (int k = 0; k < j - i - 1; k++) {
            if (temp[k] > temp[k + 1]) {
                float t = temp[k];
                temp[k] = temp[k + 1];
                temp[k + 1] = t;
            }
        }
    }

    int o = 2 * n - j;
    float arr_sum = 0;
    for (int i = 0; i < j; i++) {
        arr_sum += temp[i];
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
