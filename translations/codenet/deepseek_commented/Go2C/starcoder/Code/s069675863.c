
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64  LLONG_MAX
#define INF_BIT60  (1LL << 60)
#define INF_INT32  INT_MAX
#define INF_BIT30  (1 << 30)
#define NIL  -1
#define WHITE 0
#define GRAY  1
#define BLACK 2

typedef long long ll;

int main() {
    int S[100000 + 10];
    int x, y;
    scanf("%s", S);
    scanf("%d %d", &x, &y);

    int F[100000 + 10];
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

    int evens[100000 + 10], odds[100000 + 10];
    for (int i = 0; i < strlen(S); i++) {
        if (i % 2 == 0) {
            evens[i] = F[i];
        } else {
            odds[i] = F[i];
        }
    }

    bool dpx[100000 + 10][200010];
    bool dpy[100000 + 10][200010];
    for (int i = 0; i < strlen(S); i++) {
        for (int j = 2000; j <= 18000; j++) {
            dpx[i][j] = true;
            dpy[i][j] = true;
        }
    }

    for (int i = 0; i < strlen(S); i++) {
        int val = evens[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
            }
            if (j - val >= 2000 && i!= 0) {
                dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
            }
        }
    }
    for (int i = 0; i < strlen(S); i++) {
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

    if (dpx[strlen(S)][x + 10000] && dpy[strlen(S)][y + 10000]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

