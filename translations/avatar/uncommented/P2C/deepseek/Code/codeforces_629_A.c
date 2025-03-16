#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char cake[n][n];
    int happiness = 0;
    int chocCount = 0;
    int nfat = 1;

    for (int i = 0; i < n; i++) {
        char line[n + 1];
        scanf("%s", line);
        for (int j = 0; j < n; j++) {
            cake[i][j] = line[j];
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }
        if (chocCount > 1) {
            for (int i = chocCount; i > chocCount - 2; i--) {
                nfat *= i;
            }
            happiness += nfat / 2;
            nfat = 1;
        }
        chocCount = 0;
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }
        if (chocCount > 1) {
            for (int i = chocCount; i > chocCount - 2; i--) {
                nfat *= i;
            }
            happiness += nfat / 2;
            nfat = 1;
        }
        chocCount = 0;
    }

    printf("%d\n", happiness);
    return 0;
}
