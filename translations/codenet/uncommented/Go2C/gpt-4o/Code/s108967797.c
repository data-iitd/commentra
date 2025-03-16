#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ave(double *s, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += s[i];
    }
    return sum / n;
}

double diff(double a, double b) {
    return fabs(a - b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    double *a = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    double average = ave(a, n);

    double minDiff = 999999.9;
    int ansIndex = -1;
    for (int i = 0; i < n; i++) {
        double d = diff(a[i], average);
        if (d < minDiff) {
            minDiff = d;
            ansIndex = i;
        }
    }
    
    printf("%d\n", ansIndex);
    
    free(a);
    return 0;
}

// <END-OF-CODE>
