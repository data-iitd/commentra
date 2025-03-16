
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    float a[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }

    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    float average = sum / n;

    float minDiff = 999999.9;
    int ansIndex = -1;
    for (int i = 0; i < n; i++) {
        float diff = fabs(a[i] - average);
        if (diff < minDiff) {
            minDiff = diff;
            ansIndex = i;
        }
    }
    printf("%d\n", ansIndex);

    return 0;
}
