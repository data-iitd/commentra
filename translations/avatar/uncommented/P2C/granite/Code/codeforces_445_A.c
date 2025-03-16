
#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char s[105][105];
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                if ((i + j) % 2 == 0) {
                    s[i][j] = 'B';
                } else {
                    s[i][j] = 'W';
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", s[i]);
    }
    return 0;
}
