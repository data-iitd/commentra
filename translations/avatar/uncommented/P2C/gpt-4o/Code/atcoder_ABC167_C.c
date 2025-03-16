#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    
    int **c = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        c[i] = (int *)malloc((m + 1) * sizeof(int));
        for (int j = 0; j <= m; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    int *pre = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }

    int **l = (int **)malloc((1 << n) * sizeof(int *));
    int l_count = 0;
    for (int i = 1; i <= n; i++) {
        int *indices = (int *)malloc(i * sizeof(int));
        for (int j = 0; j < (1 << n); j++) {
            int count = 0;
            for (int k = 0; k < n; k++) {
                if (j & (1 << k)) {
                    indices[count++] = k;
                }
            }
            if (count == i) {
                l[l_count] = (int *)malloc(i * sizeof(int));
                memcpy(l[l_count], indices, i * sizeof(int));
                l_count++;
            }
        }
        free(indices);
    }

    int *rem = (int *)malloc(l_count * sizeof(int));
    int ans = 0;

    for (int i = 1; i <= m; i++) {
        int rem_count = 0;
        for (int j = 0; j < l_count; j++) {
            int ca = 0;
            for (int k = 0; k < (j + 1); k++) {
                ca += c[l[j][k]][i];
            }
            if (ca < x) {
                rem[rem_count++] = j;
            }
        }
        if (rem_count > 0) {
            for (int j = rem_count - 1; j >= 0; j--) {
                free(l[rem[j]]);
                for (int k = rem[j]; k < l_count - 1; k++) {
                    l[k] = l[k + 1];
                }
                l_count--;
            }
        }
        if (l_count == 0) {
            printf("-1\n");
            break;
        }
    }

    if (l_count > 0) {
        for (int i = 0; i < l_count; i++) {
            int ca = 0;
            for (int j = 0; j < (i + 1); j++) {
                ca += c[l[i][j]][0];
            }
            if (ans == 0) {
                ans = ca;
            } else {
                ans = (ans < ca) ? ans : ca;
            }
        }
        printf("%d\n", ans);
    }

    for (int i = 0; i < n; i++) {
        free(c[i]);
    }
    free(c);
    free(pre);
    for (int i = 0; i < l_count; i++) {
        free(l[i]);
    }
    free(l);
    free(rem);

    return 0;
}

// <END-OF-CODE>
