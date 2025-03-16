#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char arrs[n][m];
    for (int i = 0; i < n; i++) {
        scanf("%s", arrs[i]);
    }

    int length[n];
    int index = 0;
    int returnDex = -1;

    for (int i = 0; i < n; i++) {
        int dexG = -1, dexS = -1;
        for (int j = 0; j < m; j++) {
            if (arrs[i][j] == 'G') {
                dexG = j;
            } else if (arrs[i][j] == 'S') {
                dexS = j;
            }
        }

        if (dexG > dexS) {
            returnDex = i;
            break;
        }

        length[index++] = dexS - dexG;
    }

    if (returnDex != -1) {
        printf("%d\n", returnDex);
    } else {
        int uniqueLengths[index];
        int uniqueIndex = 0;
        for (int i = 0; i < index; i++) {
            int isUnique = 1;
            for (int j = 0; j < uniqueIndex; j++) {
                if (length[i] == uniqueLengths[j]) {
                    isUnique = 0;
                    break;
                }
            }
            if (isUnique) {
                uniqueLengths[uniqueIndex++] = length[i];
            }
        }
        printf("%d\n", uniqueIndex);
    }

    return 0;
}

