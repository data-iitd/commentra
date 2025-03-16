#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** li = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        li[i] = (int*)malloc((n + 1) * sizeof(int));
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &li[i][j]);
        }
    }

    int* p = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }

    int ans = 0;
    int total_switches = (1 << n);

    for (int mask = 0; mask < total_switches; mask++) {
        int valid = 1;
        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) && li[i][count++] == j + 1) {
                }
            }
            if (count % 2 != p[i]) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            ans++;
        }
    }

    printf("%d\n", ans);

    for (int i = 0; i < m; i++) {
        free(li[i]);
    }
    free(li);
    free(p);

    return 0;
}
