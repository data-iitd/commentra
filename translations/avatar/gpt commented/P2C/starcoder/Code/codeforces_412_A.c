#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char v[n];
    scanf("%s", v);
    int f = k - 1 < n - k;
    int m = min(k - 1, n - k);
    char *a[m * 2 + 1];
    for (int i = 0; i < m; i++) {
        a[i] = f? "RIGHT" : "LEFT";
    }
    for (int i = 0; i < n; i++) {
        a[m + i] = "PRINT " + v[i];
        a[m + n + i] = f? "LEFT" : "RIGHT";
    }
    for (int i = 0; i < m * 2 + n; i++) {
        printf("%s\n", a[i]);
    }
    return 0;
}
