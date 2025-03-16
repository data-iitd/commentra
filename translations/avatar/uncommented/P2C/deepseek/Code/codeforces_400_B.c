#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char grid[n][m+1];
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }

    int differences[n];
    for (int i = 0; i < n; i++) {
        int s_index = -1, g_index = -1;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                s_index = j;
            } else if (grid[i][j] == 'G') {
                g_index = j;
            }
        }
        if (s_index == -1 || g_index == -1) {
            printf("-1\n");
            return 0;
        }
        differences[i] = s_index - g_index;
    }

    int unique_differences = 0;
    int found[n];
    memset(found, 0, sizeof(found));

    for (int i = 0; i < n; i++) {
        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (differences[i] == differences[j]) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique && differences[i] >= 0) {
            unique_differences++;
        }
    }

    printf("%d\n", unique_differences);
    return 0;
}
