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

    int p[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }

    int ans = 0;
    int total_combinations = 1 << n;

    for (int mask = 0; mask < total_combinations; mask++) {
        int q[n + 1];
        int q_size = 0;
        for (int i = 1; i <= n; i++) {
            if (mask & (1 << (i - 1))) {
                q[q_size++] = i;
            }
        }

        int valid = 1;
        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < q_size; j++) {
                if (li[i][q[j]] == 1) {
                    count++;
                }
            }
            if (count % 2 != p[i]) {
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
