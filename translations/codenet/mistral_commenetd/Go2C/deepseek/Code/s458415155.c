#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000

int min(int a, int b) {
    return a < b ? a : b;
}

int solve(int n, int heights[]) {
    int t[MAX_N];
    for (int i = 0; i < n; i++) {
        t[i] = INT_MAX;
    }
    t[0] = 0;

    for (int i = 1; i < n; i++) {
        int prevIndexCost = t[i - 1];
        int heightsDiff = heights[i] - heights[i - 1];
        prevIndexCost += heightsDiff < 0 ? -heightsDiff : heightsDiff;

        if (i > 1) {
            int prevPrevIndexCost = t[i - 2];
            heightsDiff = heights[i] - heights[i - 2];
            prevPrevIndexCost += heightsDiff < 0 ? -heightsDiff : heightsDiff;

            t[i] = min(prevIndexCost, prevPrevIndexCost);
        } else {
            t[i] = prevIndexCost;
        }
    }

    return t[n - 1];
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

