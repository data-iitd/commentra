
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int h[n];
    int good[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        good[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if (h[a] > h[b]) {
            good[b] = 0;
        } else if (h[a] < h[b]) {
            good[a] = 0;
        } else {
            good[a] = 0;
            good[b] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += good[i];
    }
    printf("%d\n", ans);
    return 0;
}
