#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, i, j, k, len, returnDex;
    char arrs[1000][1000];
    int length[1000];
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%s", arrs[i]);
    }
    for (i = 0; i < n; i++) {
        len = 0;
        for (j = 0; j < strlen(arrs[i]); j++) {
            if (arrs[i][j] == 'G') {
                k = j;
                while (arrs[i][k]!= 'S') {
                    k++;
                }
                len = k - j;
            }
        }
        length[i] = len;
    }
    for (i = 0; i < n; i++) {
        if (length[i] == 0) {
            returnDex = -1;
            break;
        }
    }
    if (returnDex == -1) {
        printf("%d\n", returnDex);
    } else {
        printf("%d\n", n);
    }
    return 0;
}

