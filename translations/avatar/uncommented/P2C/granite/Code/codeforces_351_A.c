
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    double arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
        arr[i] = fmod(arr[i], 1);
    }
    qsort(arr, n, sizeof(double), cmpfunc);
    int o = 2 * n - n;
    double arr_sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i]!= 0) {
            o--;
            arr_sum += arr[i];
        }
    }
    double res = 1e9;
    for (int i = 0; i <= n; i++) {
        if (i + o >= n) {
            double temp = fabs(i - arr_sum);
            if (temp < res) {
                res = temp;
            }
        }
    }
    printf("%.3f\n", res);
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(double*)a - *(double*)b );
}

