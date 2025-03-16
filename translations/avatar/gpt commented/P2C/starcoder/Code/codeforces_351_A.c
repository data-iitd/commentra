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
    float arr_sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] - (int)arr[i]!= 0) {
            arr_sum += arr[i] - (int)arr[i];
        }
    }
    int o = 2 * n - (int)arr_sum;
    float res = 2e9;
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            res = fmin(res, fabs(i - arr_sum));
        }
    }
    printf("%.3f", res);
    return 0;
}
