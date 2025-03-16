#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char ans[n][m + 1]; // +1 for null terminator

    for (int i = 0; i < n; i++) {
        char str[m + 1]; // +1 for null terminator
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
        ans[i][m] = '\0'; // null terminate the string
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", ans[i]);
    }

    return 0;
}

// <END-OF-CODE>
