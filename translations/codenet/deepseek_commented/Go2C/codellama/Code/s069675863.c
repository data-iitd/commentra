
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD 1000000007
#define ALPHABET_NUM 26
#define INF_INT64 9223372036854775807
#define INF_BIT60 1 << 60
#define INF_INT32 2147483647
#define INF_BIT30 1 << 30
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2



int main(void) {
    char *S;
    int x, y;
    int *F;
    int cur;
    int i, j;
    int val;
    bool *dpx[10000];
    bool *dpy[10000];
    int evens[10000];
    int odds[10000];

    S = (char *)malloc(1000000 * sizeof(char));
    scanf("%s", S);
    scanf("%d %d", &x, &y);

    F = (int *)malloc(1000000 * sizeof(int));
    cur = 0;
    for (i = 0; i < strlen(S); i++) {
        if (S[i] == 'F') {
            cur++;
        } else {
            F[i] = cur;
            cur = 0;
        }
    }
    F[i] = cur;

    for (i = 0; i < strlen(S); i++) {
        if (i % 2 == 0) {
            evens[i] = F[i];
        } else {
            odds[i] = F[i];
        }
    }

    for (i = 0; i < strlen(S); i++) {
        dpx[i] = (bool *)malloc(10000 * sizeof(bool));
        dpy[i] = (bool *)malloc(10000 * sizeof(bool));
    }

    dpx[0][10000], dpy[0][10000] = true, true;
    for (i = 0; i < strlen(S); i++) {
        val = evens[i];
        for (j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
            }
            if (j - val >= 2000 && i != 0) {
                dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
            }
        }
    }
    for (i = 0; i < strlen(S); i++) {
        val = odds[i];
        for (j = 2000; j <= 18000; j++) {
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

