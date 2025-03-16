#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *bannedRows = (int *)calloc(n + 1, sizeof(int));
    int *bannedCols = (int *)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        if (r > 1 && r < n) bannedRows[r] = 1;
        if (c > 1 && c < n) bannedCols[c] = 1;
    }

    int answer = (n - 2) * 2;
    for (int i = 1; i <= n; i++) {
        if (bannedRows[i]) answer--;
        if (bannedCols[i]) answer--;
    }

    if (n % 2 != 0) {
        int mid = (n + 1) / 2;
        if (!bannedRows[mid] && !bannedCols[mid]) {
            answer--;
        }
    }

    printf("%d\n", answer);

    free(bannedRows);
    free(bannedCols);
    return 0;
}

/* <END-OF-CODE> */
