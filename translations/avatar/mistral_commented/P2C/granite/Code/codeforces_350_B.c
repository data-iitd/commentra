
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int t[n+1], a[n+1], cnt[n+1];
    for (int i = 0; i <= n; i++) {
        cnt[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    int ans[n+1], len = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {
            int crt[n+1], c = 0;
            int x = a[i];
            crt[c++] = i;
            while (cnt[x] == 1) {
                crt[c++] = x;
                x = a[x];
            }
            if (c > len) {
                len = c;
                for (int j = 0; j < c; j++) {
                    ans[j] = crt[c-j-1];
                }
            }
        }
    }

    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
