#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char **ans = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        ans[i] = (char *)malloc(m * sizeof(char));
    }

    for (int i = 0; i < n; i++) {
        char str[m + 1];
        scanf("%s", str);

        for (int j = 0; j < m; j++) {
            if (str[j] == '-') {
                ans[i][j] = '-';
            } else {
                if ((i + j) % 2 == 1) {
                    ans[i][j] = 'W';
                } else {
                    ans[i][j] = 'B';
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", ans[i]);
        free(ans[i]);
    }
    free(ans);

    return 0;
}
