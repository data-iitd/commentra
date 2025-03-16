#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int t[n+1], a[n+1];
    int cnt[n+1];

    for (int i = 1; i <= n; i++) {
        cnt[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    int ans[n+1], ans_size = 0;

    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {
            int crt[n+1], crt_size = 0;
            int x = a[i];
            while (cnt[x] == 1) {
                crt[crt_size++] = x;
                x = a[x];
            }
            crt[crt_size++] = x;

            if (crt_size > ans_size) {
                ans_size = crt_size;
                for (int j = 0; j < crt_size; j++) {
                    ans[j] = crt[crt_size - j - 1];
                }
            }
        }
    }

    printf("%d\n", ans_size);
    for (int i = 0; i < ans_size; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }
    printf("\n");

    return 0;
}
