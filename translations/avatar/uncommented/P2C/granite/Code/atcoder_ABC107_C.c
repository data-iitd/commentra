
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int *lst = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &lst[i]);
    }
    int lst_p[N], lst_m[N];
    int p = 0, m = 0;
    int x = 0, y = N - 1;
    int lastx = 0, lasty = N - 1;
    for (int i = 0; i < N; i++) {
        if (lst[i] == 0) {
            K--;
        }
        if (lst[i] > 0) {
            lst_p[p] = lst[i];
            p++;
        } else if (lst[i] < 0) {
            lst_m[m] = lst[i];
            m++;
        }
    }
    int ans = INT_MAX;
    for (int j = 0; j <= K; j++) {
        if (j > lastx || K - j > lasty) {
            continue;
        }
        int p = 0, m = 0;
        if (j > 0) {
            p = lst_p[j - 1];
        }
        if (K - j > 0) {
            m = lst_m[lasty - (K - j)];
        }
        ans = fmin(ans, 2 * p + fabs(m));
        ans = fmin(ans, p + 2 * fabs(m));
    }
    printf("%d\n", ans);
    free(lst);
    return 0;
}
