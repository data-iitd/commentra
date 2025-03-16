
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

bool dpx[MAX_N][MAX_N];
bool dpy[MAX_N][MAX_N];

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    char S[MAX_N];
    scanf("%s", S);

    int F[MAX_N];
    int cur = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == 'F') {
            cur++;
        } else {
            F[i] = cur;
            cur = 0;
        }
    }
    F[strlen(S)] = cur;

    int evens[MAX_N], odds[MAX_N];
    int evens_len = 0, odds_len = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (i % 2 == 0) {
            evens[evens_len++] = F[i];
        } else {
            odds[odds_len++] = F[i];
        }
    }

    dpx[0][10000] = true;
    dpy[0][10000] = true;
    for (int i = 0; i < evens_len; i++) {
        int val = evens[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
            }
            if (j - val >= 2000 && i != 0) {
                dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
            }
        }
    }
    for (int i = 0; i < odds_len; i++) {
        int val = odds[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
            }
            if (j - val >= 2000) {
                dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
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

