
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int t[n + 1], a[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int cnt[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }

    int ans[n + 1], ans_len = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {
            int crt[n + 1], crt_len = 0;
            int x = a[i];
            crt[crt_len++] = i;
            while (cnt[x] == 1) {
                crt[crt_len++] = x;
                x = a[x];
            }
            if (crt_len > ans_len) {
                ans_len = crt_len;
                for (int j = 0; j < crt_len; j++) {
                    ans[j] = crt[j];
                }
            }
        }
    }

    for (int i = ans_len - 1; i >= 0; i--) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
