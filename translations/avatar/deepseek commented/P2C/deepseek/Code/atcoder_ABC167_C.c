#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 15
#define MAX_M 10

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    int c[MAX_N][MAX_M + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    int pre[MAX_N];
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }

    int l[1 << MAX_N][MAX_N];
    int rem[1 << MAX_N][MAX_N];
    int l_size = 0;
    int rem_size = 0;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int comb[i];
        for (int j = 0; j < i; j++) {
            comb[j] = j;
        }
        do {
            for (int j = 0; j < i; j++) {
                l[l_size][j] = comb[j];
            }
            l_size++;
        } while (next_combination(comb, comb + i, pre + n));
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < l_size; j++) {
            int ca = 0;
            for (int k = 0; k < n; k++) {
                ca += c[l[j][k]][i];
            }
            if (ca < x) {
                rem[rem_size][0] = j;
                rem_size++;
            }
        }
        for (int j = 0; j < rem_size; j++) {
            for (int k = rem[j][0]; k < l_size - 1; k++) {
                l[k][0] = l[k + 1][0];
            }
            l_size--;
        }
        rem_size = 0;
    }

    if (l_size == 0) {
        printf("-1\n");
        return 0;
    }

    for (int i = 0; i < l_size; i++) {
        int ca = 0;
        for (int j = 0; j < n; j++) {
            ca += c[l[i][j]][0];
        }
        if (ans == 0 || ca < ans) {
            ans = ca;
        }
    }

    printf("%d\n", ans);
    return 0;
}

