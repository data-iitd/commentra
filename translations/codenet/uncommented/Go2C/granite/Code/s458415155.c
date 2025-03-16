
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int heights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    int t[n];
    for (int i = 0; i < n; i++) {
        t[i] = INT_MAX;
    }
    t[0] = 0;
    for (int i = 1; i < n; i++) {
        if (t[i-1] + abs(heights[i]-heights[i-1]) < t[i]) {
            t[i] = t[i-1] + abs(heights[i]-heights[i-1]);
        }
        if (i > 1 && t[i-2] + abs(heights[i]-heights[i-2]) < t[i]) {
            t[i] = t[i-2] + abs(heights[i]-heights[i-2]);
        }
    }
    printf("%d\n", t[n-1]);
    return 0;
}
