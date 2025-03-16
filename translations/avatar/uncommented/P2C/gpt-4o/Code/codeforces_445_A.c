#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    char l[n][m + 1]; // +1 for the null terminator

    for (int i = 0; i < n; i++) {
        scanf("%s", l[i]);
        for (int j = 0; j < m; j++) {
            if (l[i][j] == '.') {
                if ((i + j) & 1) {
                    l[i][j] = 'W';
                } else {
                    l[i][j] = 'B';
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", l[i]);
    }

    return 0;
}

// <END-OF-CODE>
