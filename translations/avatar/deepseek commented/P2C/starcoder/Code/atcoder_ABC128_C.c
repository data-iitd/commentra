#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int li[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &li[i][j]);
        }
    }
    int p[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }
    int q[n];
    for (int i = 0; i < n; i++) {
        q[i] = i + 1;
    }
    int v[n];
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < (1 << i); j++) {
            int s[i];
            int k = 0;
            for (int l = 0; l < i; l++) {
                if (j & (1 << l)) {
                    s[k++] = q[l];
                }
            }
            for (int l = 0; l < m; l++) {
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    if (s[k] == li[l][k]) {
                        cnt++;
                    }
                }
                if (cnt % 2!= p[l]) {
                    break;
                }
            } else {
                ans += pow(2, n - i);
            }
        }
    }
    printf("%d", ans);
    return 0;
}

