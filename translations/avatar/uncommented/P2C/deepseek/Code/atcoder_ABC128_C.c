#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** li = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        li[i] = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 1; j <= n; j++) {
            scanf("%d", &li[i][j]);
        }
    }

    int p[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    int q[n];
    int q_size = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            int bulb = li[i][j];
            int found = 0;
            for (int k = 0; k < q_size; k++) {
                if (q[k] == bulb) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                q[q_size++] = bulb;
            }
        }
    }

    int r[n];
    for (int i = 1; i <= n; i++) {
        r[i - 1] = i;
    }

    int v[n - q_size];
    int v_size = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < q_size; j++) {
            if (r[i] == q[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            v[v_size++] = r[i];
        }
    }

    int ans = 0;
    int total_combinations = 1 << (n - q_size);
    for (int i = 0; i < total_combinations; i++) {
        int valid = 1;
        for (int j = 0; j < m; j++) {
            int count = 0;
            for (int k = 1; k <= n; k++) {
                if (li[j][k] && (i & (1 << (k - 1)))) {
                    count++;
                }
            }
            if (count % 2 != p[j]) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            ans += 1;
        }
    }

    printf("%d\n", ans);

    for (int i = 0; i < m; i++) {
        free(li[i]);
    }
    free(li);

    return 0;
}
