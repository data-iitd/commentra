#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int iabs(int x) {
    return x < 0 ? -x : x;
}

int solve(int n, int* heights) {
    int t[n];
    for (int i = 0; i < n; i++) {
        t[i] = INT_MAX;
    }

    t[0] = 0;
    for (int i = 1; i < n; i++) {
        if (t[i-1] + iabs(heights[i] - heights[i-1]) < t[i]) {
            t[i] = t[i-1] + iabs(heights[i] - heights[i-1]);
        }
        if (i > 1 && t[i-2] + iabs(heights[i] - heights[i-2]) < t[i]) {
            t[i] = t[i-2] + iabs(heights[i] - heights[i-2]);
        }
    }

    return t[n-1];
}

int main() {
    int n;
    scanf("%d", &n);
    int heights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    int ans = solve(n, heights);
    printf("%d\n", ans);
    return 0;
}

