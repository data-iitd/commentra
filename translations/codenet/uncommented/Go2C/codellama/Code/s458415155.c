
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 100000

int iabs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int solve(int n, int heights[]) {
    int t[MAX_N];
    memset(t, 0, sizeof(int) * MAX_N);

    t[0] = 0;
    for (int i = 1; i < n; i++) {
        if (t[i-1] + iabs(heights[i] - heights[i-1]) < t[i]) {
            t[i] = t[i-1] + iabs(heights[i] - heights[i-1]);
        }
        if (i > 1) {
            if (t[i-2] + iabs(heights[i] - heights[i-2]) < t[i]) {
                t[i] = t[i-2] + iabs(heights[i] - heights[i-2]);
            }
        }
    }

    return t[n-1];
}

int main() {
    int n;
    scanf("%d", &n);
    int heights[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    int ans = solve(n, heights);
    printf("%d\n", ans);
    return 0;
}

