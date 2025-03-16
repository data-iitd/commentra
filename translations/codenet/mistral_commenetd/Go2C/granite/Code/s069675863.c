
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char S[100001];
    int x, y;
    scanf("%s %d %d", S, &x, &y);

    int evens[100001];
    int odds[100001];
    int evens_len = 0;
    int odds_len = 0;

    for (int i = 0; i < strlen(S); i++) {
        if (i % 2 == 0) {
            evens[evens_len++] = S[i] - '0';
        } else {
            odds[odds_len++] = S[i] - '0';
        }
    }

    int dpx[8001][20001];
    int dpy[8001][20001];

    for (int i = 0; i < 8001; i++) {
        for (int j = 0; j < 20001; j++) {
            dpx[i][j] = 0;
            dpy[i][j] = 0;
        }
    }

    dpx[0][10000] = 1;
    dpy[0][10000] = 1;

    for (int i = 0; i < evens_len; i++) {
        for (int j = 20000; j >= 0; j--) {
            if (j + evens[i] <= 20000) {
                dpx[i + 1][j + evens[i]] |= dpx[i][j];
            }
            if (j - evens[i] >= 0) {
                dpx[i + 1][j - evens[i]] |= dpx[i][j];
            }
        }
    }

    for (int i = 0; i < odds_len; i++) {
        for (int j = 20000; j >= 0; j--) {
            if (j + odds[i] <= 20000) {
                dpy[i + 1][j + odds[i]] |= dpy[i][j];
            }
            if (j - odds[i] >= 0) {
                dpy[i + 1][j - odds[i]] |= dpy[i][j];
            }
        }
    }

    if (dpx[evens_len][x + 10000] && dpy[odds_len][y + 10000]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
