#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    
    int a[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int v[MAX_N];
    int ans = INT_MAX;

    for (int k = 0; k < n; k++) {
        int kans = 0;
        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                v[i] = min(v[i], a[n + i - k]);
            } else {
                v[i] = min(v[i], a[i - k]);
            }
            kans += v[i];
        }
        ans = min(ans, kans + k * x);
    }

    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
