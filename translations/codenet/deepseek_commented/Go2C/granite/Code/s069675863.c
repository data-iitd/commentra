

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 9223372036854775807
#define INF_BIT60 1LL << 60
#define INF_INT32 2147483647
#define INF_BIT30 1 << 30
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

const int MAX_N = 100000;

int x, y;
char S[MAX_N];
int F[MAX_N];
int evens[MAX_N], odds[MAX_N];
int evens_size, odds_size;
int dpx[MAX_N][2 * MAX_N], dpy[MAX_N][2 * MAX_N];

void init() {
    scanf("%s", S);
    scanf("%d %d", &x, &y);

    int cur = 0;
    for (int i = 0; S[i]!= '\0'; i++) {
        if (S[i] == 'F') {
            cur++;
        } else {
            F[evens_size++] = cur;
            cur = 0;
        }
    }
    F[evens_size++] = cur;

    for (int i = 0; i < evens_size; i++) {
        if (i % 2 == 0) {
            evens[i] = F[i];
        } else {
            odds[odds_size++] = F[i];
        }
    }

    memset(dpx, 0, sizeof(dpx));
    memset(dpy, 0, sizeof(dpy));
    dpx[0][MAX_N] = dpy[0][MAX_N] = 1;

    for (int i = 0; i < evens_size; i++) {
        for (int j = 0; j < 2 * MAX_N; j++) {
            if (dpx[i][j] == 1) {
                if (j + evens[i] < 2 * MAX_N) {
                    dpx[i + 1][j + evens[i]] = 1;
                }
                if (j - evens[i] >= 0) {
                    dpx[i + 1][j - evens[i]] = 1;
                }
            }
        }
    }

    for (int i = 0; i < odds_size; i++) {
        for (int j = 0; j < 2 * MAX_N; j++) {
            if (dpy[i][j] == 1) {
                if (j + odds[i] < 2 * MAX_N) {
                    dpy[i + 1][j + odds[i]] = 1;
                }
                if (j - odds[i] >= 0) {
                    dpy[i + 1][j - odds[i]] = 1;
                }
            }
        }
    }
}

int main() {
    init();

    if (dpx[evens_size][x + MAX_N] == 1 && dpy[odds_size][y + MAX_N] == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}