
#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    int count = 0;
    float sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] - (int)arr[i]!= 0) {
            count++;
            sum += arr[i] - (int)arr[i];
        }
    }

    int res = 2e9;
    for (int i = 0; i <= n; i++) {
        if (i + 2 * n - count >= n) {
            res = fminf(res, fabsf(i - sum));
        }
    }

    printf("%.3f\n", res);

    return 0;
}
