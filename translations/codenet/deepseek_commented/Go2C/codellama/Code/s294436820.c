
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define INF 1000000007
#define INF2 1000000009
#define INF3 998244353

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define minll(a, b) (((a) < (b)) ? (a) : (b))
#define minf(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define maxll(a, b) (((a) > (b)) ? (a) : (b))
#define maxf(a, b) (((a) > (b)) ? (a) : (b))
#define abs(a) (((a) < 0) ? (-(a)) : (a))
#define absf(a) (((a) < 0) ? (-(a)) : (a))

int egcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int d = egcd(b, a % b, y, x);
    *y -= a / b * *x;
    return d;
}

int gcd(int a, int b) {
    int x, y;
    return egcd(a, b, &x, &y);
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);
    int **m = (int **)malloc(sizeof(int *) * h);
    for (int i = 0; i < h; i++) {
        m[i] = (int *)malloc(sizeof(int) * w);
        char *s = (char *)malloc(sizeof(char) * (w + 1));
        scanf("%s", s);
        for (int j = 0; j < w; j++) {
            m[i][j] = s[j];
        }
    }

    int result = 0;
    for (int i = 0; i < (1 << h); i++) {
        for (int k = 0; k < (1 << w); k++) {
            int **tmp = (int **)malloc(sizeof(int *) * h);
            for (int j = 0; j < h; j++) {
                tmp[j] = (int *)malloc(sizeof(int) * w);
                memcpy(tmp[j], m[j], sizeof(int) * w);
            }
            for (int j = 0; j < h; j++) {
                int hPainted = (1 << j & i);
                if (hPainted > 0) {
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1;
                    }
                }
            }
            for (int j = 0; j < w; j++) {
                int wPainted = (1 << j & k);
                if (wPainted > 0) {
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1;
                    }
                }
            }
            int count = 0;
            for (int j = 0; j < h; j++) {
                for (int l = 0; l < w; l++) {
                    if (tmp[j][l] == 35) {
                        count++;
                    }
                }
            }
            if (count == k) {
                result++;
            }
        }
    }
    printf("%d\n", result);
    return 0;
}

