#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int c[n];
    for (int i = 0; i < n; i++) {
        char grid[m + 1];
        scanf("%s", grid);
        int s_index = -1, g_index = -1;
        for (int j = 0; j < m; j++) {
            if (grid[j] == 'S') {
                s_index = j;
            } else if (grid[j] == 'G') {
                g_index = j;
            }
        }
        if (s_index != -1 && g_index != -1) {
            c[i] = s_index - g_index;
        } else {
            c[i] = -1; // If 'S' or 'G' is missing in the row, mark it as -1
        }
    }

    int unique_non_negative = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] >= 0) {
            int is_unique = 1;
            for (int j = 0; j < i; j++) {
                if (c[j] == c[i]) {
                    is_unique = 0;
                    break;
                }
            }
            if (is_unique) {
                unique_non_negative++;
            }
        }
    }

    printf("%d\n", unique_non_negative == 0 ? -1 : unique_non_negative);

    return 0;
}
