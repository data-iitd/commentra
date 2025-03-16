#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    int *p = (int *)malloc(n * sizeof(int));
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int ans = 1200001;
    int tot;
    int ok;

    for (int bits = 0; bits < 1 << n; bits++) {
        int skill[m];
        for (int i = 0; i < m; i++) {
            skill[i] = 0;
        }

        tot = 0;
        ok = 1;
        for (int i = 0; i < n; i++) {
            if (bits & (1 << i)) {
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
    }

    if (ans != 1200001) {
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
