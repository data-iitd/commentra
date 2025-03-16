
#include <stdio.h>
#include <math.h>

int main() {
    int n, t, a;
    scanf("%d %d %d", &n, &t, &a);

    int minDiff = INT_MAX;
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        int h;
        scanf("%d", &h);
        int diff = abs(t - h * 6);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i + 1;
        }
    }
    printf("%d\n", minIdx);

    return 0;
}
