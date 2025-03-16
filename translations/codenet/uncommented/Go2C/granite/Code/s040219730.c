
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    int p[n];
    for (int i = 0; i < n; i++) {
        p[i] = -1;
    }

    int l, r;
    int ans[q];
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        l--; r--;

        for (int j = l; j <= r; j++) {
            if (p[c[j] - 1]!= -1) {
                p[c[j] - 1] = -1;
            }
            p[c[j] - 1] = j;
        }

        int sum = 0;
        for (int j = l; j <= r; j++) {
            if (p[c[j] - 1] == j) {
                sum++;
            }
        }

        ans[i] = sum;
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
