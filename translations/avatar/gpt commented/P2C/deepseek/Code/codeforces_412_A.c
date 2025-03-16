#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char v[n + 1];
    scanf("%s", v);

    char d[2][4] = {"LEFT", "RIGHT"};
    int f = k - 1 < n - k;
    int m = (f) ? k - 1 : n - k;

    char a[1000][100];
    int index = 0;

    for (int i = 0; i < m; i++) {
        strcpy(a[index++], d[!f]);
    }

    for (int i = 0; i < strlen(v); i++) {
        char c = v[strlen(v) - 1 - i * (1 - 2 * f)];
        strcpy(a[index++], "PRINT ");
        strncat(a[index - 1], &c, 1);
        strcpy(a[index++], d[f]);
    }

    for (int i = 0; i < index - 1; i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}
