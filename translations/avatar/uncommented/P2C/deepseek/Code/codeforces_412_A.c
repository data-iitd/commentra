#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char v[100];
    scanf("%s", v);
    char *d[] = {"LEFT", "RIGHT"};
    int f = k - 1 < n - k;
    int m = (k - 1 < n - k) ? k - 1 : n - k;
    char *a[100];
    for (int i = 0; i < m; i++) {
        a[i] = (char *)malloc(10 * sizeof(char));
        strcpy(a[i], d[!f]);
    }
    for (int i = 0; i < strlen(v); i += 2 - 2 * f) {
        a[m + i] = (char *)malloc(15 * sizeof(char));
        sprintf(a[m + i], "PRINT %c", v[i]);
        a[m + i + 1] = (char *)malloc(6 * sizeof(char));
        strcpy(a[m + i + 1], d[f]);
    }
    for (int i = 0; i < m + strlen(v) - 1; i++) {
        printf("%s\n", a[i]);
        free(a[i]);
    }
    return 0;
}

