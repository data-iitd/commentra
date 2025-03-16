
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x, a[1000], v[1000], ans = 1000000000;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        v[i] = a[i];
    }
    for (int k = 0; k < n; k++) {
        int kans = 0;
        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                v[i] = (v[i] < a[n + i - k]? v[i] : a[n + i - k]);
            } else {
                v[i] = (v[i] < a[i - k]? v[i] : a[i - k]);
            }
            kans += v[i];
        }
        ans = (ans < kans + k * x? ans : kans + k * x);
    }
    printf("%d\n", ans);
    return 0;
}
