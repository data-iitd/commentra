#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char cake[n][n + 1]; // +1 for null terminator
    int happiness = 0;
    int chocCount = 0;
    int nfat = 1;

    for (int i = 0; i < n; i++) {
        scanf("%s", cake[i]);
        chocCount = 0;

        for (int j = 0; j < strlen(cake[i]); j++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }

        if (chocCount > 1) {
            for (int k = chocCount; k > chocCount - 2; k--) {
                nfat *= k;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
    }

    chocCount = 0;
    for (int j = 0; j < n; j++) {
        chocCount = 0;
        for (int i = 0; i < n; i++) {
            if (cake[i][j] == 'C') {
                chocCount++;
            }
        }

        if (chocCount > 1) {
            for (int k = chocCount; k > chocCount - 2; k--) {
                nfat *= k;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
    }

    printf("%d\n", happiness);
    return 0;
}

// <END-OF-CODE>
