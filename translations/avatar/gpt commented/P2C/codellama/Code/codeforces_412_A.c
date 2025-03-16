#include <stdio.h>

int main() {
    int n, k, i, m, f;
    char v[1000000];
    char d[2][6] = {"LEFT", "RIGHT"};
    char a[1000000];

    scanf("%d %d", &n, &k);
    scanf("%s", v);

    f = k - 1 < n - k;
    m = k - 1 < n - k ? k - 1 : n - k;

    for (i = 0; i < m; i++) {
        a[i] = d[!f];
    }

    for (i = 0; i < n; i++) {
        a[i + m] = "PRINT ";
        a[i + m + 1] = v[i];
        a[i + m + 2] = d[f];
    }

    for (i = 0; i < n + m + 2; i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}

