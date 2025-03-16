#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double AbsDiffFloat64(double n1, double n2) {
    return fabs(n1 - n2);
}

int main() {
    int n;
    double t, a;

    // Read n, t, a
    scanf("%d %lf %lf", &n, &t, &a);
    
    double *heights = (double *)malloc(n * sizeof(double));
    
    // Read heights
    for (int i = 0; i < n; i++) {
        scanf("%lf", &heights[i]);
    }

    double minDiff = AbsDiffFloat64(t - heights[0] * 0.006, a);
    int minIdx = 0;

    for (int i = 1; i < n; i++) {
        double diff = AbsDiffFloat64(t - heights[i] * 0.006, a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i;
        }
    }

    printf("%d\n", minIdx + 1);

    free(heights);
    return 0;
}

/* <END-OF-CODE> */
