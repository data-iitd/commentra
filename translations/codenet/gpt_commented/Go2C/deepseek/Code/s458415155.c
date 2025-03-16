#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to return the absolute value of an integer
int abs(int x) {
    return x < 0 ? -x : x;
}

// Function to solve the problem using dynamic programming
int solve(int n, int* heights) {
    int* t = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        t[i] = INT_MAX;
    }

    t[0] = 0;
    for (int i = 1; i < n; i++) {
        if (t[i - 1] + abs(heights[i] - heights[i - 1]) < t[i]) {
            t[i] = t[i - 1] + abs(heights[i] - heights[i - 1]);
        }
        if (i > 1 && t[i - 2] + abs(heights[i] - heights[i - 2]) < t[i]) {
            t[i] = t[i - 2] + abs(heights[i] - heights[i - 2]);
        }
    }

    int result = t[n - 1];
    free(t);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int* heights = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int ans = solve(n, heights);
    printf("%d\n", ans);

    free(heights);
    return 0;
}

