
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, chocCount, nfat, happiness;
    char cake[100][100];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", cake[i]);
    }

    happiness = 0;
    for (i = 0; i < n; i++) {
        chocCount = 0;
        for (j = 0; j < n; j++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }
        if (chocCount > 1) {
            nfat = 1;
            for (j = chocCount; j > chocCount-2; j--) {
                nfat *= j;
            }
            happiness += nfat / 2;
        }
    }

    for (j = 0; j < n; j++) {
        chocCount = 0;
        for (i = 0; i < n; i++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }
        if (chocCount > 1) {
            nfat = 1;
            for (i = chocCount; i > chocCount-2; i--) {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
    }

    printf("%d", happiness);
    return 0;
}

