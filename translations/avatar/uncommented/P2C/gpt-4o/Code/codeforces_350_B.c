#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *t = (int *)malloc((n + 1) * sizeof(int));
    int *a = (int *)malloc((n + 1) * sizeof(int));
    int *cnt = (int *)calloc(n + 1, sizeof(int));
    int *ans = (int *)malloc((n + 1) * sizeof(int));
    int ans_len = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {
            int crt_len = 0;
            int *crt = (int *)malloc((n + 1) * sizeof(int));
            crt[crt_len++] = i;
            int x = a[i];

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
            free(crt);
        }
    }

    printf("%d\n", ans_len);
    for (int i = ans_len - 1; i >= 0; i--) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    free(t);
    free(a);
    free(cnt);
    free(ans);
    
    return 0;
}

/* <END-OF-CODE> */
