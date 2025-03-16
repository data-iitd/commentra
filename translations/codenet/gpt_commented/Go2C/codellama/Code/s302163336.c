#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, i, ai, bi, h[100000], good[100000];
    char str[100000];

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        good[i] = 1;
    }

    for (i = 0; i < m; i++) {
        scanf("%d %d", &ai, &bi);
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
    for (i = 0; i < n; i++) {
        if (good[i]) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}

