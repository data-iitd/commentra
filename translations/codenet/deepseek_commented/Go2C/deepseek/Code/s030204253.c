#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(double*)a - *(double*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    double a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    while (n > 1) {
        qsort(a, n, sizeof(double), compare);
        double na[n - 1];
        for (int j = 2; j < n; j++) {
            na[j - 2] = a[j];
        }
        na[n - 2] = (a[0] + a[1]) / 2;
        n--;
        for (int i = 0; i < n; i++) {
            a[i] = na[i];
        }
    }
    printf("%.6f\n", a[0]);
    return 0;
}

