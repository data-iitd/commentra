#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int readInt() {
    int n;
    scanf("%d", &n);
    return n;
}

int readLong() {
    long n;
    scanf("%ld", &n);
    return n;
}

double readDouble() {
    double n;
    scanf("%lf", &n);
    return n;
}

char* readLine() {
    char *str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);
    return str;
}

int main() {
    int n = readInt();
    int m = readInt();
    bool bannedRows[n + 1], bannedCols[n + 1];
    memset(bannedRows, false, sizeof(bannedRows));
    memset(bannedCols, false, sizeof(bannedCols));

    for (int i = 0; i < m; i++) {
        int r = readInt();
        if (r > 1 && r < n) bannedRows[r] = true;
        int c = readInt();
        if (c > 1 && c < n) bannedCols[c] = true;
    }

    int answer = (n - 2) * 2;
    int rowCount = 0, colCount = 0;
    for (int i = 2; i <= n; i++) {
        if (bannedRows[i]) rowCount++;
        if (bannedCols[i]) colCount++;
    }
    answer -= rowCount + colCount;

    if (n % 2 != 0) {
        int mid = (n + 1) / 2;
        if (!bannedRows[mid] && !bannedCols[mid]) {
            answer--;
        }
    }

    printf("%d\n", answer);
    return 0;
}

