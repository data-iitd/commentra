
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    int x, y;
    scanf("%d %d", &x, &y);

    int f[100001] = {0};
    int i, j, k;
    for (i = 0, j = 0; s[i]; i++) {
        if (s[i] == 'F') {
            j++;
        } else {
            f[j]++;
            j = 0;
        }
    }
    f[j]++;

    int dpx[100001][20001] = {0};
    int dpy[100001][20001] = {0};
    dpx[0][10000] = 1;
    dpy[0][10000] = 1;
    for (i = 0; i < 100000; i++) {
        for (j = 20000; j >= 0; j--) {
            if (dpx[i][j]) {
                if (j + f[i] <= 20000) {
                    dpx[i + 1][j + f[i]] = 1;
                }
                if (j - f[i] >= 0) {
                    dpx[i + 1][j - f[i]] = 1;
                }
            }
            if (dpy[i][j]) {
                if (j + f[i] <= 20000) {
                    dpy[i + 1][j + f[i]] = 1;
                }
                if (j - f[i] >= 0) {
                    dpy[i + 1][j - f[i]] = 1;
                }
            }
        }
    }

    if (dpx[100000][x + 10000] && dpy[100000][y + 10000]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
