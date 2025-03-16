#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1e14

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n], v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    memcpy(v, a, n * sizeof(int));
    long long ans = INF;
    for (int k = 0; k < n; k++) {
        long long kans = 0;
        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                v[i] = min(v[i], a[n + i - k]);
            } else {
                v[i] = min(v[i], a[i - k]);
            }
            kans += v[i];
        }
        kans += (long long)k * x;
        ans = min(ans, kans);
    }
    printf("%lld\n", ans);
    return 0;
}
