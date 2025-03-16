
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 8000
#define MAX_M 20000

bool dpx[MAX_N][MAX_M];
bool dpy[MAX_N][MAX_M];

void updateDPX(int index, int val) {
    for (int j = 2000; j <= 18000; j++) {
        if (j + val <= 18000) {
            dpx[index + 1][j + val] = dpx[index + 1][j + val] || dpx[index][j];
        }
        if (j - val >= 2000 && index != 0) {
            dpx[index + 1][j - val] = dpx[index + 1][j - val] || dpx[index][j];
        }
    }
}

void updateDPY(int index, int val) {
    for (int j = 2000; j <= 18000; j++) {
        if (j + val <= 18000) {
            dpy[index + 1][j + val] = dpy[index + 1][j + val] || dpy[index][j];
        }
        if (j - val >= 2000) {
            dpy[index + 1][j - val] = dpy[index + 1][j - val] || dpy[index][j];
        }
    }
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_M; j++) {
            dpx[i][j] = false;
            dpy[i][j] = false;
        }
    }

    int len_evens = 0;
    int len_odds = 0;
    int evens[MAX_N];
    int odds[MAX_N];

    for (int i = 0; i < MAX_N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp % 2 == 0) {
            evens[len_evens] = tmp;
            len_evens++;
        } else {
            odds[len_odds] = tmp;
            len_odds++;
        }
    }

    for (int i = 0; i < len_evens; i++) {
        updateDPX(i, evens[i]);
    }

    for (int i = 0; i < len_odds; i++) {
        updateDPY(i, odds[i]);
    }

    if (dpx[len_evens][x + 10000] && dpy[len_odds][y + 10000]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

