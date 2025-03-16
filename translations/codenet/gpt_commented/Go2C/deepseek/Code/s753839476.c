#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double AbsDiffFloat64(double n1, double n2) {
    return fabs(n1 - n2);
}

int main() {
    int n, t, i;
    double a, h;
    double minDiff = 0.0, diff = 0.0;
    int minIdx = 0;

    scanf("%d %d %lf", &n, &t, &a);
    double heights[n];

    for (i = 0; i < n; i++) {
        scanf("%lf", &heights[i]);
    }

    minDiff = fabs(t - heights[0] * 0.006 - a);
    minIdx = 0;

    for (i = 1; i < n; i++) {
        diff = fabs(t - heights[i] * 0.006 - a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i;
        }
    }

    printf("%d\n", minIdx + 1);
    return 0;
}
