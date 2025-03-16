#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int iabs(int x) {
    return x < 0 ? -x : x;
}

int solve(int n, int heights[]) {
    int *t = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        t[i] = INT_MAX;
    }

    t[0] = 0;
    for (int i = 1; i < n; i++) {
        if (t[i - 1] + iabs(heights[i] - heights[i - 1]) < t[i]) {
            t[i] = t[i - 1] + iabs(heights[i] - heights[i - 1]);
        }
        if (i > 1) {
            if (t[i - 2] + iabs(heights[i] - heights[i - 2]) < t[i]) {
                t[i] = t[i - 2] + iabs(heights[i] - heights[i - 2]);
            }
        }
    }

    int result = t[n - 1];
    free(t);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int *heights = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    int ans = solve(n, heights);
    printf("%d\n", ans);
    free(heights);
    return 0;
}

//<END-OF-CODE>
