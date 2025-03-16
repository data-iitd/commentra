#include <stdio.h>
#include <stdlib.h>

int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
}

int main() {
    int n = nextInt();
    int m = nextInt();
    int h[n];
    int good[n];
    for (int i = 0; i < n; i++) {
        h[i] = nextInt();
        good[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int ai = nextInt() - 1;
        int bi = nextInt() - 1;
        if (h[ai] > h[bi]) {
            good[bi] = 0;
        } else if (h[ai] < h[bi]) {
            good[ai] = 0;
        } else {
            good[ai] = 0;
            good[bi] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
