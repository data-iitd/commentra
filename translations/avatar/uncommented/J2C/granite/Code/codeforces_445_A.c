
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int n, m;
    scanf("%d %d", &n, &m);
    char ans[n][m];
    for (int i = 0; i < n; i++) {
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
        for (int j = 0; j < m; j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//END-OF-CODE