#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 20
#define MAX_W 20
#define BLACK 35

int countBlack(int h, int w, int m[MAX_H][MAX_W]) {
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == BLACK) {
                count++;
            }
        }
    }
    return count;
}

int solve(int h, int w, int a, int m[MAX_H][MAX_W]) {
    int result = 0;
    for (int i = 0; i < (1 << h); i++) {
        for (int k = 0; k < (1 << w); k++) {
            int tmp[MAX_H][MAX_W];
            memcpy(tmp, m, sizeof(int) * h * w);
            for (int j = 0; j < h; j++) {
                if (i & (1 << j)) {
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1;
                    }
                }
            }
            for (int j = 0; j < w; j++) {
                if (k & (1 << j)) {
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1;
                    }
                }
            }
            if (countBlack(h, w, tmp) == a) {
                result++;
            }
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);
    int m[MAX_H][MAX_W];
    for (int i = 0; i < h; i++) {
        char s[MAX_W + 1];
        scanf("%s", s);
        for (int j = 0; j < w; j++) {
            m[i][j] = (int)s[j];
        }
    }

    int answer = solve(h, w, k, m);
    printf("%d\n", answer);
    return 0;
}
