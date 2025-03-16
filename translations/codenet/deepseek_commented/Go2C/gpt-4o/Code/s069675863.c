#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MOD 1000000007
#define ALPHABET_NUM 26
#define INF_INT64 LLONG_MAX
#define INF_BIT60 (1LL << 60)
#define INF_INT32 INT_MAX
#define INF_BIT30 (1 << 30)
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_SIZE 20000

bool dpx[100][MAX_SIZE];
bool dpy[100][MAX_SIZE];

void readString(char *buffer) {
    scanf("%s", buffer);
}

int readInt() {
    int value;
    scanf("%d", &value);
    return value;
}

void readInt2(int *x, int *y) {
    scanf("%d %d", x, y);
}

int main() {
    char S[100000];
    readString(S);
    
    int x, y;
    readInt2(&x, &y);

    int F[100000];
    int cur = 0;
    int F_size = 0;

    for (int i = 0; S[i] != '\0'; i++) {
        if (S[i] == 'F') {
            cur++;
        } else {
            F[F_size++] = cur;
            cur = 0;
        }
    }
    F[F_size++] = cur;

    // Debug print
    for (int i = 0; i < F_size; i++) {
        printf("%d ", F[i]);
    }
    printf("\n");

    int evens[100000], odds[100000];
    int even_count = 0, odd_count = 0;

    for (int i = 0; i < F_size; i++) {
        if (i % 2 == 0) {
            evens[even_count++] = F[i];
        } else {
            odds[odd_count++] = F[i];
        }
    }

    memset(dpx, false, sizeof(dpx));
    memset(dpy, false, sizeof(dpy));
    dpx[0][10000] = true;
    dpy[0][10000] = true;

    for (int i = 0; i < even_count; i++) {
        int val = evens[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
            }
            if (j - val >= 2000 && i != 0) {
                dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
            }
        }
    }

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

    if (dpx[even_count][x + 10000] && dpy[odd_count][y + 10000]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
<<<<<<< HEAD
=======

// <END-OF-CODE>
>>>>>>> 98c87cb78a (data updated)
