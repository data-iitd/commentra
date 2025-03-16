#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int a[12];
        int b[12];
        int c[12];
        int d[12];
        int e[12];
        int f[12];
        int g[12];
        int h[12];
        int tot = 0;
        char x[12];
        scanf("%s", x);
        for (int j = 0; j < 12; j++) {
            if (x[j] == 'O') {
                a[j] = 0;
                b[j] = 0;
                c[j] = 0;
                d[j] = 0;
                e[j] = 0;
                f[j] = 0;
                g[j] = 0;
                h[j] = 0;
            } else {
                a[j] = 1;
                b[j] = 1;
                c[j] = 1;
                d[j] = 1;
                e[j] = 1;
                f[j] = 1;
                g[j] = 1;
                h[j] = 1;
            }
        }
        for (int j = 1; j < 12; j++) {
            if (12 % j == 0) {
                if (help(j, 12 / j, a) || help(j, 12 / j, b) || help(j, 12 / j, c) || help(j, 12 / j, d) || help(j, 12 / j, e) || help(j, 12 / j, f) || help(j, 12 / j, g) || help(j, 12 / j, h)) {
                    tot++;
                }
            }
        }
        printf("%d", tot);
        for (int j = 1; j < 12; j++) {
            if (12 % j == 0) {
                if (help(j, 12 / j, a) || help(j, 12 / j, b) || help(j, 12 / j, c) || help(j, 12 / j, d) || help(j, 12 / j, e) || help(j, 12 / j, f) || help(j, 12 / j, g) || help(j, 12 / j, h)) {
                    printf(" %dx%d", j, 12 / j);
                }
            }
        }
        printf("\n");
    }
    return 0;
}

int help(int a, int b, int *l) {
    int tot[12];
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            tot[i * a + j] = l[i * a + j];
        }
    }
    for (int i = 0; i < b; i++) {
        if (tot[i * a] + tot[i * a + 1] + tot[i * a + 2] + tot[i * a + 3] + tot[i * a + 4] + tot[i * a + 5] + tot[i * a + 6] + tot[i * a + 7] + tot[i * a + 8] + tot[i * a + 9] + tot[i * a + 10] + tot[i * a + 11] == b) {
            return 1;
        }
    }
    return 0;
}

