
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define INF_INT64 9223372036854775807
#define INF_BIT60 1 << 60
#define INF_INT32 2147483647
#define INF_BIT30 1 << 30
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define ALPHABET_NUM 26

#define MAX_K 100000
#define MAX_N 100000

int a, b, c;
int k;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &k);

    int patterns[MAX_K][MAX_N];
    int pattern_num = 0;

    for (int i = 0; i < MAX_K; i++) {
        for (int j = 0; j < MAX_N; j++) {
            patterns[i][j] = NIL;
        }
    }

    for (int i = 0; i < MAX_K; i++) {
        for (int j = 0; j < MAX_N; j++) {
            if (patterns[i][j] != NIL) {
                continue;
            }

            int r = a, g = b, b = c;
            for (int j = 0; j < i; j++) {
                if (patterns[i][j] == 0) {
                    continue;
                } else if (patterns[i][j] == 1) {
                    r *= 2;
                } else if (patterns[i][j] == 2) {
                    g *= 2;
                } else if (patterns[i][j] == 3) {
                    b *= 2;
                }
            }

            if (g > r && b > g) {
                printf("Yes\n");
                return 0;
            }
        }
    }

    printf("No\n");

    return 0;
}

