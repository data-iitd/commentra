#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    int *p = (int *)malloc(n * sizeof(int));
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        a[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int ans = INT_MAX;
    for (int bits = 0; bits < (1 << n); bits++) {
        int tot = 0;
        int ok = 1;
        int *skill = (int *)calloc(m, sizeof(int));

        for (int i = 0; i < n; i++) {
            if ((bits >> i) & 1) {
                tot += p[i];
                for (int j = 0; j < m; j++) {
                    skill[j] += a[i][j];
                }
            }
        }

        for (int j = 0; j < m; j++) {
            if (skill[j] < x) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            if (ans > tot) {
                ans = tot;
            }
        }

        free(skill);
    }

    if (ans != INT_MAX) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(p);

    return 0;
}

// <END-OF-CODE>
