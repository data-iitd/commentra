#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    char *str;
    char **ans;
    int i, j;

    scanf("%d %d", &n, &m);
    ans = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        ans[i] = (char *)malloc(m * sizeof(char));
    }

    for (i = 0; i < n; i++) {
        scanf("%s", str);
        for (j = 0; j < m; j++) {
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

    for (i = 0; i < n; i++) {
        printf("%s\n", ans[i]);
    }

    for (i = 0; i < n; i++) {
        free(ans[i]);
    }
    free(ans);

    return 0;
}
