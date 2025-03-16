
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    double a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    double ave = sum / n;

    double minDiff = 999999.9;
    int ansIndex = -1;
    for (int i = 0; i < n; i++) {
        double diff = abs(a[i] - ave);
        if (diff < minDiff) {
            minDiff = diff;
            ansIndex = i;
        }
    }
    printf("%d\n", ansIndex);

    return 0;
}
