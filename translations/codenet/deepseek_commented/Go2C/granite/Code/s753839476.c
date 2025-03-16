
#include <stdio.h>
#include <math.h>

int main() {
    int n;
    float t, a;
    scanf("%d %f %f", &n, &t, &a);

    float minDiff = fabs(t - a * 0.006);
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        float h;
        scanf("%f", &h);
        float diff = fabs(t - h * 0.006);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i;
        }
    }
    printf("%d\n", minIdx + 1);
    return 0;
}
