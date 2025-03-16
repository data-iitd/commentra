
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    double *a = (double *)malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    for (int i = 0; i + 1 < n; i++) {
        qsort(a, n, sizeof(double), cmpfunc);
        double *na = (double *)malloc(sizeof(double) * (n - 2));
        for (int j = 2; j < n; j++) {
            na[j - 2] = a[j];
        }
        na[n - 2] = (a[0] + a[1]) / 2;
        free(a);
        a = na;
        n -= 1;
    }
    printf("%.10lf\n", a[0]);
    free(a);
    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(double *)a - *(double *)b);
}

