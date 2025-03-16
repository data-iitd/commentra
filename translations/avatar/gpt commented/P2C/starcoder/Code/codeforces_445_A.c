#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char **l = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        char *s = malloc(m * sizeof(char));
        scanf("%s", s);
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                if ((i + j) & 1) {
                    s[j] = 'W';
                } else {
                    s[j] = 'B';
                }
            }
        }
        l[i] = s;
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", l[i]);
    }
    return 0;
}
