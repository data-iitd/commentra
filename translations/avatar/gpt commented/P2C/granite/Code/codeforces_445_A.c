
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char grid[n][m];

    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                grid[i][j] = (i + j) % 2 == 0? 'B' : 'W';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}
