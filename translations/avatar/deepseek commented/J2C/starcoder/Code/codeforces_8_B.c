#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, x = 0, y = 0, k = 0, dx, dy;
    int flag = 1;
    char s[100];
    char ch[100];
    int co[2][101];

    scanf("%s", s);
    for (i = 0; i < strlen(s); ++i) {
        ch[i] = s[i];
    }
    co[0][k] = x;
    co[1][k] = y;
    ++k;
    for (i = 0; i < strlen(s); ++i) {
        switch (ch[i]) {
            case 'L': --x; break;
            case 'R': ++x; break;
            case 'U': ++y; break;
            case 'D': --y; break;
        }
        co[0][k] = x;
        co[1][k] = y;
        ++k;
    }
    for (i = 0; i < k - 3; ++i) {
        for (j = i + 3; j < k; ++j) {
            dx = co[0][i] - co[0][j];
            dy = co[1][i] - co[1][j];
            if (dx < 0) dx *= -1;
            if (dy < 0) dy *= -1;
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) break;
    }
    if (flag) printf("OK\n");
    else printf("BUG\n");
    return 0;
}

