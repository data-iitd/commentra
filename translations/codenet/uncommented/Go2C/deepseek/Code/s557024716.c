#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 1LL << 60
#define INF_INT32 1 << 30
#define NIL -1

typedef long long ll;

void init() {
    // bufio.ScanWords <---> bufio.ScanLines
}

void main() {
    int a, b, c, k;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &k);

    int patterns[4][k+1];
    memset(patterns, 0, sizeof(patterns));

    for (int i = 0; i <= k; i++) {
        patterns[0][i] = 1;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                patterns[1][j] = 1;
            } else {
                patterns[1][j] = patterns[0][j] + patterns[1][j-1];
            }
        }
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                patterns[2][j] = 1;
            } else {
                patterns[2][j] = patterns[1][j] + patterns[2][j-1];
            }
        }
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                patterns[3][j] = 1;
            } else {
                patterns[3][j] = patterns[2][j] + patterns[3][j-1];
            }
        }
        memcpy(patterns[0], patterns[1], sizeof(patterns[1]));
        memcpy(patterns[1], patterns[2], sizeof(patterns[2]));
        memcpy(patterns[2], patterns[3], sizeof(patterns[3]));
    }

    int r = a * patterns[3][k];
    int g = b * patterns[2][k];
    int b = c * patterns[1][k];

    if (g > r && b > g) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}
