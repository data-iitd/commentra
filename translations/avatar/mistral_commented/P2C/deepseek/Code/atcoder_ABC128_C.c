#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int li[m][1000];
    int p[m];

    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &li[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }

    int ans = 0;

    for (int bit = 0; bit < (1 << n); bit++) {
        int q[n + 1];
        memset(q, 0, sizeof(q));

        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                q[i + 1] = 1;
            }
        }

        int flag = 1;

        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < li[i][0]; j++) {
                if (q[li[i][j]] == 1) {
                    count++;
                }
            }
            if (count % 2 != p[i]) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
