#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int t[n + 1];
    t[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans[n + 1];
    int cnt[n + 1];
    for (int i = 0; i <= n; i++) {
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {
            int x = a[i];
            int crt[n + 1];
            crt[0] = i;
            int j = 1;
            while (cnt[x] == 1) {
                crt[j] = x;
                x = a[x];
                j++;
            }
            if (j > ans[0]) {
                for (int k = 0; k < j; k++) {
                    ans[k] = crt[k];
                }
            }
        }
    }
    printf("%d\n", ans[0]);
    for (int i = 1; i <= ans[0]; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
