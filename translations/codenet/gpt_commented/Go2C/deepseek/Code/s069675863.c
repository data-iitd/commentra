#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 (int64_t)math.MaxInt64
#define INF_BIT60 (1LL << 60)
#define INF_INT32 (int32_t)math.MaxInt32
#define INF_BIT30 (1 << 30)
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

void init() {
    // Initialize custom input reading function and buffered output
    // This part is not directly translatable to C, as C does not have built-in functions for input and output buffering
}

char S[8000];
int x, y;
bool dpx[8000][20000], dpy[8000][20000];

void main() {
    // Read the input string and target coordinates
    scanf("%s", S);
    scanf("%d %d", &x, &y);

    int F[8000];
    int cur = 0;

    // Count consecutive 'F's and store in F
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == 'F') {
            cur++;
        } else {
            F[i] = cur;
            cur = 0;
        }
    }
    F[strlen(S)] = cur;

    int evens[8000], odds[8000];
    int even_count = 0, odd_count = 0;

    // Separate counts into even and odd indexed slices
    for (int i = 0; i <= strlen(S); i++) {
        if (i % 2 == 0) {
            evens[even_count++] = F[i];
        } else {
            odds[odd_count++] = F[i];
        }
    }

    // Initialize the dynamic programming tables for x and y
    memset(dpx, false, sizeof(dpx));
    memset(dpy, false, sizeof(dpy));
    dpx[0][10000] = true;
    dpy[0][10000] = true;

    // Fill the dynamic programming table for even indexed counts
    for (int i = 0; i < even_count; i++) {
        int val = evens[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
            }
            if (j - val >= 2000) {
                dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
            }
        }
    }

    // Fill the dynamic programming table for odd indexed counts
    for (int i = 0; i < odd_count; i++) {
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

    // Check if the target coordinates can be reached
    if (dpx[even_count][x + 10000] && dpy[odd_count][y + 10000]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

