#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char **l = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        l[i] = (char *)malloc(m * sizeof(char));
    }

    for (int i = 0; i < n; i++) {
        char s[m + 1];
        scanf("%s", s);
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                if ((i + j) % 2 == 0) {
                    l[i][j] = 'B';
                } else {
                    l[i][j] = 'W';
                }
            } else {
                l[i][j] = s[j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", l[i]);
        free(l[i]);
    }
    free(l);

    return 0;
}
